#include "Unit_ved.hpp"

int VED::max(double a, double b, double c){
    if(a >= b && a >= c) return 0;
    if(b >= a && b >= c) return 1;
    if(c >= a && c >= b) return 2; 
    return 0;
}
Choice VED::MakeChoice(){
    if(isRock) return (Choice)0;
    if(!flag_first){
        flag_first = !flag_first;
        my_choice = (Choice)1;
        return (Choice)1;
    } 
    if(opp_choice != 2)
        coefs[(int)opp_choice + 1] = coefs[(int)opp_choice + 1] + 0.5;
    else
        coefs[0] = coefs[0] + 0.5;
    if((my_choice > opp_choice && !(my_choice == 2 && opp_choice == 0)) || (my_choice == 0 && opp_choice == 2)){
       win++; 
       draw = 0;
       coefs[(int)my_choice] = coefs[(int)my_choice] + coefWin;
    } 
    if((opp_choice > my_choice && !(opp_choice != 2 && my_choice == 2)) || (opp_choice == 0 && my_choice == 2)){
        lose++;
        draw = 0;
        coefs[(int)my_choice] = coefs[(int)my_choice] - coefLose;
    } 
    if(opp_choice == my_choice)
    {
        coefs[(int)my_choice] = coefs[(int)my_choice] - coefDraw;
    }
    draw++;
    if(draw > 8) return Choice(rand() % 3);
    my_choice = (Choice)max(coefs[0], coefs[1], coefs[2]);
    //std::cout << (int)my_choice << "\n";
    return my_choice;
}
void VED::SetResult(Choice enemy_choice){
    opp_choice = enemy_choice;
}
void VED::StartBattle(int win_count){
    if(win_count != 0) win_count_ = win_count;
    else win_count_ = 1;
    coefs[0] = 1;
    coefs[1] = 1;
    coefs[2] = 1;
    roundesCounter = 0;
}
VED::VED(std::string name){
    name = name_;
    win_phrase_ = "2 EZ";
    lose_phrase_ = "GG";
}
std::string VED::GetName(){
    return name_;
}
std::string VED::GetWinPhrase(){
    return win_phrase_;
}
std::string VED::GetLosePhrase(){
    //std::cout << coefs[0] << " " << coefs[1] << " " << coefs[2] << " ";
    return lose_phrase_;
}
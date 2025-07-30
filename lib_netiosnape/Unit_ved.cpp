#include "Unit_ved.hpp"

int VED::max(double a,double b, double c){
    if(a > b && a > c) return 0;
    if(b > a && b > c) return 1;
    if(c > a && c > b) return 2; 
    return 0;
}
Choice VED::MakeChoice(){
    if(!flag_first){
        flag_first = !flag_first;
        my_choice = (Choice)2;
        return (Choice)2;
    } 
    if((my_choice > opp_choice && !(my_choice == 2 && opp_choice == 0)) || (my_choice == 0 && opp_choice == 2)){
       win++; 
       coefs[(int)my_choice] = coefs[(int)my_choice] + coefWin;
    } 
    if((opp_choice > my_choice && !(opp_choice != 2 && my_choice == 2)) || (opp_choice == 0 && my_choice == 2)){
        lose++;
        coefs[(int)my_choice] = coefs[(int)my_choice] - coefLose;
    } 
    my_choice = (Choice)max(coefs[0], coefs[1], coefs[2]);
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
std::string VED::GetName(){
    return name_;
}
std::string VED::GetWinPhrase(){
    return win_phrase_;
}
std::string VED::GetLosePhrase(){
    return lose_phrase_;
}
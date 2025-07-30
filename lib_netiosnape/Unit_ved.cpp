#include "Unit_ved.hpp"

int VED::max(double a,double b, double c){
    if(a > b && a > c) return 0;
    if(b > a && b > c) return 1;
    if(c > a && c > b) return 2; 
}
Choice VED::MakeChoice(){
    if(!flag_first){
        flag_first = !flag_first;
        my_choice = 2;
        return 2;
    } 
    if((my_choice > opp_choice && my_choice != 2) || (my_choice == 0 && opp_choice == 2)){
       win++; 
       coef[my_choice] =+ coefWin;
    } 
    if((opp_choice > my_choice && opp_choice != 2) || (opp_choice == 0 && my_choice == 2)){
        lose++;
        coef[my_choice] =- coefLose;
    } 
    my_choice = max(coefs[0], coefs[1], coefs[2]);
    return my_choice;
}
void VED::SetResult(Choice enemy_choice){
    opp_choice = enemy_choice;
}
void VED::StartBattle(int win_count){
    if(win_count != 0) win_count_ = win_count;
    else win_count_ = 1;
    coefs[3] = {1, 1, 1};
    roundesCounter = 0;
}
std::string VED::GetName(){
    std::string name = "VED";
    return name;
}
std::string VED::GetWinPhrase(){
    std::string winPhrase = "2 EZ";
    return winPhrase;
}
std::string VED::GetLosePhrase(){
    std::string losePhrase = "GG";
    return losePhrase;
}
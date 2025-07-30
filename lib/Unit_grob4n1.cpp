#include <iostream>
#include "Unit_grob4n1.h"

Unit_grob4n1::Unit_grob4n1(std::string mName){
    name_ = mName;
}
Choice Unit_grob4n1::MakeChoice(){
    return choice;
}
void Unit_grob4n1::SetResult(Choice enemy_choice){
    if(choice == enemy_choice){
        if(draw_in_a_row > 5){
            if(enemy_choice == ROCK){
                enemy_choice = PAPER;
            }
            else if(enemy_choice == PAPER){
                enemy_choice = SCISSORS;
            }
            else{
                enemy_choice = ROCK;
            }
            draw_in_a_row = -1;
        }
        draw_in_a_row++;
        draw++;
    }
    else if(choice - enemy_choice == 1 || choice - enemy_choice == -2){
        my_wins++;
        draw_in_a_row = 0;
    }
    else{
        other_wins++;
        draw_in_a_row = 0;
    }
    if(draw == 0 && my_wins == 2 && other_wins == 2){
        enemy_choice == PAPER;
    }
    if(draw == 0 & my_wins == 0 & other_wins == 5){
        enemy_choice == PAPER;
    }
    choice = enemy_choice;
}
void Unit_grob4n1::StartBattle(int win_count){
    my_wins = 0;
    other_wins = 0;
}
std::string Unit_grob4n1::GetName(){
    return name_;
}
std::string Unit_grob4n1::GetWinPhrase(){
    return win_phrase_;
}
std::string Unit_grob4n1::GetLosePhrase(){
    return lose_phrase_;
}
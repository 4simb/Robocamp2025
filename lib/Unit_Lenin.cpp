#include <iostream>
#include "Unit_Lenin.h"


Choice Unit_Lenin::MakeChoice()
{
    choice = (Choice)((choice + 3 + (((last_enemy_choice - choice + 3) % 3 == 1) * 2 - 1)) % 3);
    if (not_win_count_ >= 5){
        choice = (Choice)((choice + 2) % 3);
        not_win_count_ = 0;
    }
    return choice;
}

void Unit_Lenin::SetResult(Choice enemy_choice)
{
    last_enemy_choice = enemy_choice;
    if ((choice - last_enemy_choice + 3) % 3 == 1){
        win_count_ += 1;
    }
    else {
        not_win_count_ += 1;
    }
}

void Unit_Lenin::StartBattle(int win_count)
{
    choice = ROCK;
    last_enemy_choice = ROCK;
    win_count_ = 0;
    not_win_count_ = 0;
}

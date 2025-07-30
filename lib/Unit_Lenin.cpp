#include <iostream>
#include "Unit_Lenin.h"


Choice Unit_Lenin::MakeChoice()
{
    choice = (Choice)((choice + 3 + (((last_enemy_choice - choice + 3) % 3 == 1) * 2 - 1)) % 3);
    return choice;
}

void Unit_Lenin::SetResult(Choice enemy_choice)
{
    last_enemy_choice = enemy_choice;
}

void Unit_Lenin::StartBattle(int win_count)
{
    choice = ROCK;
    last_enemy_choice = ROCK;
    win_count_ = 0;
}

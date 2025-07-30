#include "Unit_Ex7nos.h"

Ex7nos::Ex7nos() 
{
    total_battles_ = 0;
    win_count_ = 0;
    name_ = "Ex7nos";
    win_phrase_ = "I win";
    lose_phrase_ = "Bad...";
}



Choice Ex7nos::MakeChoice() 
{
    last_choice_ = Choice((last_choice_ + 1) % 3);
    return last_choice_;
}



void Ex7nos::SetResult(Choice enemy_choice) 
{
    if (last_choice_ == enemy_choice)
    { 
        return;
    }

    bool is_win;
    if((last_choice_ == ROCK && enemy_choice == SCISSORS) ||
       (last_choice_ == PAPER && enemy_choice == ROCK) ||
       (last_choice_ == SCISSORS && enemy_choice == PAPER));
       {
            is_win = true;
       }

    if (is_win = true)
    { 
        win_count_++;
    }
}



void Ex7nos::StartBattle(int battles_count) 
{
    total_battles_ = battles_count;
    win_count_ = 0;
}



std::string Ex7nos::GetName() 
{
    return name_;
}


std::string Ex7nos::GetWinPhrase() 
{
    return win_phrase_;
}


std::string Ex7nos::GetLosePhrase() 
{
    return lose_phrase_;
}


int Ex7nos::GetWinCount() 
{
    return win_count_;
}


void Ex7nos::SetWinCount(int count) 
{
    win_count_ = count;
}



int Ex7nos::GetTotalBattles() 
{
    return total_battles_;
}
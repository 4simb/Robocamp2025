#pragma once
#include <string>
#include "BaseUnit.h"

int win_count_;


enum Choice {ROCK, PAPER, SCISSORS};

class Ex7nos {
public:
    Ex7nos();
    
    Choice MakeChoice();
    void SetResult(Choice enemy_choice);
    void StartBattle(int battles_count);
    
    std::string GetName();
    std::string GetWinPhrase();
    std::string GetLosePhrase();
    
    int GetWinCount();
    void SetWinCount(int count);
    bool IsWinner();
    int GetTotalBattles();

private:
    int total_battles_;
    Choice last_choice_;
    std::string name_;
    std::string win_phrase_;
    std::string lose_phrase_;
};
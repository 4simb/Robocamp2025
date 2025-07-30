// Robocamp 2025 - rock, paper, scissors
#pragma once

#include <string>

enum Choice : int { ROCK, PAPER, SCISSORS };

class BaseUnit {
   public:
    virtual Choice MakeChoice() = 0;

    virtual void SetResult(Choice enemy_choice) = 0;

    virtual void StartBattle(int win_count) = 0;

    std::string GetName();

    std::string GetWinPhrase();

    std::string GetLosePhrase();

   protected:
    int win_count_;

    std::string name_;

    std::string win_phrase_;

    std::string lose_phrase_;
};

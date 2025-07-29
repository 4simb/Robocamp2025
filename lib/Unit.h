// Robocamp 2025 - rock, paper, scissors
#pragma once

#include <string>

enum Choice : int { ROCK, PAPER, SCISSORS };

class Unit {
   public:
    virtual Choice MakeChoice() = delete;

    virtual void GetResult(Choice enemy_choice) = delete;

    virtual void StartBattle(int win_count) = delete;

   private:
    int win_count_;

    const std::string name_;

    const std::string win_phrase_;

    const std::string lose_phrase;
};

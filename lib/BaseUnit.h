// Robocamp 2025 - rock, paper, scissors
#pragma once

#include <string>

enum Choice : int { ROCK, PAPER, SCISSORS };

class BaseUnit {
   public:
    virtual Choice MakeChoice() = 0;

    virtual void SetResult(Choice enemy_choice) = 0;

    virtual void StartBattle(int win_count) = 0;

    virtual std::string GetName() = 0;

    virtual std::string GetWinPhrase() = 0;

    virtual std::string GetLosePhrase() = 0;

    virtual int GetWinCount() = 0;

    virtual void SetWinCount(int count) = 0;

    virtual bool IsWinner() = 0;

   protected:
    int win_count_;

    const std::string name_;

    const std::string win_phrase_;

    const std::string lose_phrase_;
};

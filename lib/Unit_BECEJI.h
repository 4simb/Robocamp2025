#pragma once
#include "BaseUnit.h"

//enum Choice : int { ROCK, PAPER, SCISSORS };

class BECEJI_Strategy : BaseUnit
{
private:
    std::string name; //НАПИШИ СЮДА СВОЙ IDX
    std::string winPhrase;
    std::string losePhrase;

public:
    void unit();
    BECEJI_Strategy();
    void SetResult(Choice enemy_choice) override;
    void StartBattle(int win_count) override;
    Choice MakeChoice() override;
};
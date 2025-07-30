#pragma once
#include "BaseUnit.h"

//enum Choice : int { ROCK, PAPER, SCISSORS };

class BECEJI_Strategy : BaseUnit
{
private:
    //std::string name; //НАПИШИ СЮДА СВОЙ IDX
    std::string winPhrase;
    std::string losePhrase;
    int myChoiseRow;

    int counter, drawCounter = 0, loseCounter = 0;
    Choice enemyLast = ROCK;
    Choice myLast = SCISSORS;
    std::string name = "BECEJI";

public:
    void unit();
    BECEJI_Strategy(std::string name);
    void SetResult(Choice enemy_choice) override;
    void StartBattle(int win_count) override;
    Choice MakeChoice() override;
};
#include <iostream>
#include "Unit_BECEJI.h"
#include "BaseUnit.h"

int myChoiseRow;

int counter;
Choice enemyLast;
Choice myLast;

BECEJI_Strategy::BECEJI_Strategy()
{
    name = "BECEJI";
    winPhrase = "HaHaHa";
    losePhrase = "Oh, she*t, here we go again";
}

void BECEJI_Strategy::SetResult(Choice enemy_choice)
{
    enemyLast = enemy_choice;
}

void BECEJI_Strategy::StartBattle(int mWin_count)
{
    counter = 1;
}

Choice BECEJI_Strategy::MakeChoice()
{
    Choice choise;
    if(counter <= 2)
    {
        myChoiseRow = 2;
    }
    else
    {
        if(enemyLast - myLast == -1 | enemyLast - myLast == 2)
        {
            myChoiseRow += 2;
        }

        else if(enemyLast - myLast == -2 | enemyLast - myLast == 1){}
        else if(enemyLast - myLast == 0 )
        {
            myChoiseRow += 1;
        }
    }


    if(myChoiseRow % 3 == 0)
    {
        choise = ROCK;
    }

    else if(myChoiseRow % 3 == 1)
    {
        choise = PAPER;
    }

    else if(myChoiseRow % 3 == 2)
    {
        choise = SCISSORS;
    }

    counter++;
    myLast = choise;
    return choise;
}

void BECEJI_Strategy::unit()
{
    BECEJI_Strategy::BECEJI_Strategy();
    void SetResult();
    void StartBattle();
    Choice MakeChoice();
}
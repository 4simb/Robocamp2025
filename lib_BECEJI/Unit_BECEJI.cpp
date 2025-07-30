#include <iostream>
#include "Unit_BECEJI.h"
#include "BaseUnit.h"

BECEJI_Strategy::BECEJI_Strategy(std::string mName)
{
    winPhrase = "PACTTNJI";
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
            
            drawCounter = 0;
            loseCounter++;
            if (loseCounter < 3)
            {
                myChoiseRow += 2;
            }
            else
            {
                myChoiseRow += 1;
            }
        }

        else if(enemyLast - myLast == -2 | enemyLast - myLast == 1)
        {
            drawCounter = 0;
            loseCounter = 0;
        }
        else if(enemyLast - myLast == 0)
        {
            drawCounter++;
            loseCounter = 0;
            myChoiseRow += 1;
            if(drawCounter < 3)
            {
                myChoiseRow += 1;
            }
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
    //BECEJI_Strategy::BECEJI_Strategy(name);
    void SetResult();
    void StartBattle();
    Choice MakeChoice();
}
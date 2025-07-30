#include <iostream>
#include "BaseUnit.h"
/*

enum Choice : int { ROCK, PAPER, SCISSORS };

class BaseUnit {
   public:
    virtual Choice MakeChoice() = 0;

    virtual void SetResult(Choice enemy_choice) = 0;

    virtual void StartBattle(int win_count) = 0;

    virtual std::string GetName() = 0;

    virtual std::string GetWinPhrase() = 0;

    virtual std::string GetLosePhrase() = 0;

   protected:
    int win_count_;

    const std::string name_;

    const std::string win_phrase_;

    const std::string lose_phrase_;
};
*/
class UnitOff : public BaseUnit{
    private:
        Choice prev3 = prev2;
        Choice prev2 = prev;
        Choice prev = enemy_choice;
        Choice prevmy;

    public:
        UnitOff(Choice mPrev = nullptr, Choice mPrev2 = nullptr, Choice mPrev3 = nullptr, Choice prevmy = nullptr);
        void setPrev(Choice mPrev);
        void setPrev2(Choice mPrev2);
        void setPrev3(Choice mPrev3);
        void setPrevmy(Choice mPrevmy);
        Choice getPrev();
        Choice getPrev2();
        Choice getPrev3();
        Choice getPrevmy();
        Unit_Choice(int Choice){
            if(getPrev() == getPrev2() && getPrev2() == getPrev3()){
                if (getPrev() == ROCK){
                    MakeChoice(PAPER);
                }
                if (getPrev() == SCISSORS){
                    MakeChoice(ROCK);
                }
                if (getPrev() == PAPER){
                    MakeChoice(SCISSORS);
                }
            }else if{
                if(getPrev() == getPrev2()){
                if (getPrev() == ROCK){
                    MakeChoice(PAPER);
                }
                if (getPrev() == SCISSORS){
                    MakeChoice(ROCK);
                }
                if (getPrev() == PAPER){
                    MakeChoice(SCISSORS);
                }
                }
            }else if{
                if (getPrev() == ROCK && getPrevmy() == SCISSORS){
                    MakeChoice(ROCK);
                }
                if (getPrev() == ROCK && getPrevmy() == PAPER){
                    MakeChoice(SCISSORS);
                }
                if (getPrev() == ROCK && getPrevmy() == ROCK){
                    MakeChoice(SCISSORS);
                }
                if (getPrev() == PAPER && getPrevmy() == SCISSORS){
                    MakeChoice(PAPER);
                }
                if (getPrev() == PAPER && getPrevmy() == PAPER){
                    MakeChoice(PAPER);
                }
                if (getPrev() == PAPER && getPrevmy() == ROCK){
                    MakeChoice(ROCK);
                }
                if (getPrev() == SCISSORS && getPrevmy() == SCISSORS){
                    MakeChoice(ROCK);
                }
                if (getPrev() == SCISSORS && getPrevmy() == PAPER){
                    MakeChoice(ROCK);
                }
                if (getPrev() == SCISSORS && getPrevmy() == ROCK){
                    MakeChoice(PAPER);
                }
                
            }
        }
        if (getPrev)
};
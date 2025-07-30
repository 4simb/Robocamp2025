
#include "BaseUnit.h"

class Test1 : public BaseUnit{
private:
    int winAmmount;
    int loseAmmount;
    int winsNeed;
    Choice currChoice;
    
    void chooseNext(){
        currChoice = Choice((currChoice + 1) % 3);
    }
public:
    Test1(std::string mName = "DefaultName"){
        name_ = mName;
        win_phrase_ = mName + " WINS!!!!";
        lose_phrase_ = mName + " LOOSES!!!!";
        currChoice = Choice(rand() % 3);
    }

    virtual Choice MakeChoice(){
        return currChoice;
    };

    virtual void SetResult(Choice enemy_choice){
        if (enemy_choice == Choice::PAPER){
            if (currChoice == ROCK){
                chooseNext();
            }
            if (currChoice == PAPER){
                chooseNext();
            }
        }
        
        if (enemy_choice == Choice::ROCK){
            if (currChoice == SCISSORS){
                chooseNext();
            }
            if (currChoice == ROCK){
                chooseNext();
            }
        }
        
        if (enemy_choice == Choice::SCISSORS){
            if (currChoice == PAPER){
                chooseNext();
            }
            if (currChoice == SCISSORS){
                chooseNext();
            }
        }
    }

    void StartBattle(int win_count){
        winAmmount = 0;
        loseAmmount = 0;
        winsNeed = 0;
        currChoice = Choice::PAPER;
    }
};




class Test2 : public BaseUnit{
private:
    int winAmmount;
    int loseAmmount;
    int winsNeed;
    Choice currChoice;
    int cycle;
    void chooseNext(){
        currChoice = Choice((currChoice + 2) % 3);
    }
public:
    Test2(std::string mName = "DefaultName"){
        name_ = mName;
        win_phrase_ = mName + " WINS!!!!";
        lose_phrase_ = mName + " LOOSES!!!!";
        currChoice = Choice(rand() % 3);
    }

    virtual Choice MakeChoice(){
        
        cycle++;
        if (cycle >= 3){
            cycle = 0;
            chooseNext();
        }
        return currChoice;
    };

    virtual void SetResult(Choice enemy_choice){
       "BRUH";
    }

    void StartBattle(int win_count){
        winAmmount = 0;
        loseAmmount = 0;
        winsNeed = 0;
        currChoice = Choice::PAPER;
    }
};
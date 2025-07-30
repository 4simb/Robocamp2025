#ifndef UNIT_VED_HPP
#define UNIT_VED_HPP
#include <iostream>
#include "..//lib/BaseUnit.h"

class VED : public BaseUnit{
    private:
        int roundesCounter = 0;
        bool flag_first = false;
        Choice opp_choice;
        Choice my_choice = PAPER;
        double coefs[3] = {1, 1, 1};
        double coefWin = 1, coefLose = 1, coefDraw = 0.5;
        int max(double a, double b, double c);
        std::string lose_phrase_ = "GG";
        std::string win_phrase_ = "2 EZ";
        std::string name_ = "VED";
        int lose, win;
    public:
        bool isRock = false;
        Choice MakeChoice();
        void SetResult(Choice enemy_choice);
        void StartBattle(int win_count = 1);
        std::string GetName();
        std::string GetWinPhrase();
        std::string GetLosePhrase();
};

#endif
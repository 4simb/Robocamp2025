#ifndef UNIT_VED.HPP
#define UNIT_VED.HPP
#include "lib/BaseUnit.h"

class VED : public Unit{
    private:
        int roundesCounter = 0;
        bool flag_first = false;
        Choice opp_choice;
        Choice my_choice = PAPER;
        double coefs[3] = {1, 1, 1};
        double coefWin = 1/(double)win_count_, coefLose = 1/(double)win_count_;
        int max(double a, double b, double c);
        int lose, win;
    public:
        Choice MakeChoice();
        void SetResult(Choice enemy_choice);
        void StartBattle(int win_count = 1);
        std::string GetName();
        std::string GetWinPhrase();
        std::string GetLosePhrase();
};

#endif
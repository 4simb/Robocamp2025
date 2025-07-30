#include<iostream> 
#include<vector>
#include <algorithm>
#include "BaseUnit.h"


class Unit_Matvey : public BaseUnit{
    public:
        Unit_Matvey();

        std::string GetLosePhrase();
        std::string GetWinPhrase();

        void StartBattle(int n) override;

        Choice MakeChoice() override;

        void SetResult(Choice ch) override;

        void sayOutcome();

    private:
        const std::string name_ = "Matvey";
        const std::string win_phrase_ = "Ill be back";
        const std::string lose_phrase_ = "OOOOOOOOOOOOOOOOOOOOOOH";
        std::vector<Choice> ref = {Choice::ROCK, Choice::PAPER, Choice::SCISSORS, Choice::ROCK};
        std::vector<std::string> lbl = {"ROCK", "PAPER", "SCISSORS"};

        std::vector<int> oLog; //outcome log
        std::vector<Choice> pLog; //play log
        int winsCnt;
        int lossCnt;
        int drawsCnt;

        Choice currPlay;
};
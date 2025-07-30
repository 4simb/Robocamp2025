#include  "BaseUnit.h"

class Unit_Lenin : public BaseUnit{
    private:
        Choice choice;
        Choice last_enemy_choice;
        int win_count_;
        int not_win_count_;
        

        std::string name_ = "Lenin";

        const std::string win_phrase_ = "Glory to the Soviet Union!";

        const std::string lose_phrase_ = "This is a shame, comrades.";
        
    public:
        Unit_Lenin();

        Choice MakeChoice();

        void SetResult(Choice enemy_choice);

        void StartBattle(int win_count);
};


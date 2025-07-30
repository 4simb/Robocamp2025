#include  <lib/BaseUnit.h>

class Unit_Lenin : public BaseUnit{
    private:
        int choice = 1;
        int last_enemy_choice = 0;
        int win_count_ = 0;

        const std::string name_ = "Lenin";

        const std::string win_phrase_ = "Glory to the Soviet Union!";

        const std::string lose_phrase_ = "This is a shame, comrades.";
        
    public:
        Choice MakeChoice();

        void SetResult(Choice enemy_choice);

        void StartBattle(int win_count);

        std::string GetName();

        std::string GetWinPhrase();

        std::string GetLosePhrase();
};


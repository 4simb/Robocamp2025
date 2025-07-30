class Unit_Ruslan : public BaseUnit{
private:
    Choice choice = SCISSORS;
    std::string name_ = "Ruslan";
    std::string win_phrase_ = "Win Win Win";
    std::string lose_phrase_ = "...........";
    int win_count_;
    int my_wins = 0;
    int other_wins = 0;
    int draw_in_a_row = 0;
    int draw = 0;
    // bool flag = 0;
    // int win_lose = 0;
public:
    Choice MakeChoice();
    void SetResult(Choice enemy_choice);
    void StartBattle(int win_count);
    std::string GetName();
    std::string GetWinPhrase();
    std::string GetLosePhrase();
}
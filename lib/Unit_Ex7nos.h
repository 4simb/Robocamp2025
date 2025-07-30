#pragma once
#include "BaseUnit.h"
#include <string>

class Ex7nos : public BaseUnit {
private:
    bool is_win_;
    int total_balltes_ = 0; 
    int win_count_;
    std::string name_; 
    std::string win_phrase_; 
    std::string lose_phrase_;
    Choice last_choice_; 

public:
    Ex7nos() 
    {
        win_count_ = 0; 
        name_ = "Ex7nos"; 
        win_phrase_ = "I won!"; 
        lose_phrase_ = "I don't won"; 
        last_choice_ = ROCK; 
    }



    Choice MakeChoice() 
    {
        last_choice_ = Choice((last_choice_ + 1) % 3); 
        return last_choice_; 
    }



    void SetResult(Choice enemy_choice) 
    {
        if (last_choice_ == enemy_choice)
        { 
            return;
        }
        
        if((last_choice_ == ROCK && enemy_choice == SCISSORS) || 
           (last_choice_ == PAPER && enemy_choice == ROCK) || 
           (last_choice_ == SCISSORS && enemy_choice == PAPER)); 
        {
            is_win_ = true; 
        }

        if (is_win_ == true) 
        {
            win_count_++; 
        }
    }



    void StartBattle(int battles_count) override 
    {
        total_balltes_ = battles_count; 
        win_count_ = 0;  
        last_choice_ = ROCK; 
    }
    


    std::string GetName()  
    { 
        return name_; 
    } 

    std::string GetWinPhrase()   
    { 
        return win_phrase_; 
    } 

    std::string GetLosePhrase()  
    { 
        return lose_phrase_; 
    } 

    int GetWinCount()  
    {  
        return win_count_; 
    } 

    void SetWin_Count_(int count) 
    { 
        win_count_ = count; 
    }   

    int GetTotalBattles() 
    { 
        return total_balltes_;  
    } 

    bool IsWinner()  
    { 
    if (win_count_ >= 1) 
    { 
        return true; 
    } 
    else 
    { 
        return false;
    } 
} 
}; 
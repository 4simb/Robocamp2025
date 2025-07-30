#include"Unit_Matvey.h"


Unit_Matvey::Unit_Matvey(){
    winsCnt = 0;
    lossCnt = 0;
    drawsCnt = 0;
}

std::string Unit_Matvey::GetLosePhrase(){
    return win_phrase_;
}
std::string Unit_Matvey::GetWinPhrase(){
    return lose_phrase_;
}

void Unit_Matvey::StartBattle(int n){
    winsCnt = 0;
    lossCnt = 0;
    oLog.clear();
    pLog.clear();
}

Choice Unit_Matvey::MakeChoice(){
    if (winsCnt + lossCnt + drawsCnt < 20){
    
        if(oLog.size() == 0){  //first play
            currPlay = Choice::ROCK;
            std::cout << "ROCK" << '\n';
            return currPlay;
        }

        if(oLog[oLog.size() - 1] == 1){
            currPlay = pLog[pLog.size() - 1];
        } else {
            Choice ch = pLog[pLog.size() - 1];
            currPlay = ref[std::find(ref.begin(), ref.end(), ch) - ref.begin() + 1];
        }
        std::cout << lbl[std::find(ref.begin(), ref.end(), currPlay) - ref.begin()] << '\n';
        return currPlay;
    }
    else {
        if (winsCnt - lossCnt > 0){

            if(oLog[oLog.size() - 1] == 1){
                currPlay = pLog[pLog.size() - 1];
            } else {
                Choice ch = pLog[pLog.size() - 1];
                currPlay = ref[std::find(ref.begin(), ref.end(), ch) - ref.begin() + 1];
            }
            std::cout << lbl[std::find(ref.begin(), ref.end(), currPlay) - ref.begin()] << '\n';
            return currPlay;
        }
        else {
            if(oLog[oLog.size() - 1] == 1){
                Choice ch = pLog[pLog.size() - 1];
                currPlay = ref[std::find(ref.begin(), ref.end(), ch) - ref.begin() + 1];
            } else {
                currPlay = pLog[pLog.size() - 1];
            }

        }
    }
    
    
}

void Unit_Matvey::SetResult(Choice ch){
    pLog.push_back(ch);

    if (ch == currPlay){
        oLog.push_back(0);
    } else if (ref[std::find(ref.begin(), ref.end(), ch) - ref.begin() + 1] == currPlay){
        oLog.push_back(1);
        winsCnt++;
    } else {
        oLog.push_back(-1);
        lossCnt++;
    }
}

void Unit_Matvey::sayOutcome(){
    if (winsCnt > lossCnt){
        std::cout << "WIN" << '\t';
    } else {
        std::cout << "LOSS" << '\t';
    }

    std::cout << winsCnt << ' ' << lossCnt;
}


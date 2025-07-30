#include"Unit_Matvey.h"


Unit_Matvey::Unit_Matvey(){
    winsCnt = 0;
    lossCnt = 0;
    drawsCnt = 0;
    MODE = 0;
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
    drawsCnt = 0;
    battlesCnt = n;
    oLog.clear();
    pLog.clear();
}

Choice Unit_Matvey::MakeChoice(){
    if (winsCnt + lossCnt + drawsCnt > battlesCnt / 5  && winsCnt - lossCnt <= 0 && MODE == 0){
        MODE = 1;
    }
    if (winsCnt + lossCnt + drawsCnt > battlesCnt / 5 * 2 && winsCnt - lossCnt <= 0 && MODE == 1){
        MODE = 2;
    }

    if (MODE == 0){
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
        //std::cout << lbl[std::find(ref.begin(), ref.end(), currPlay) - ref.begin()] << '\n';
        return currPlay;
    }
    else if (MODE == 1){
        if(oLog[oLog.size() - 1] == 1){
            Choice ch = pLog[pLog.size() - 1];
            currPlay = ref[std::find(ref.begin(), ref.end(), ch) - ref.begin() + 1];
        } else {
            currPlay = pLog[pLog.size() - 1];
        }
        return currPlay;
    }
    else if (MODE == 2){
        currPlay = ref[(oLog.size() + 55221 - int(pLog.size() * 0.3) + int(drawsCnt * 0.6)) % 4];
        return currPlay;
    }
}

void Unit_Matvey::SetResult(Choice ch){
    pLog.push_back(ch);

    if (ch == currPlay){
        oLog.push_back(0);
        drawsCnt++;
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


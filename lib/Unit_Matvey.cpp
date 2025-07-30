#include"Unit_Matvey.h"


Unit_Matvey::Unit_Matvey(){
    winsCnt = 0;
    lossCnt = 0;
}

std::string Unit_Matvey::sayLoosePhrase(){
    return win_phrase_;
}
std::string Unit_Matvey::sayWinPhrase(){
    return lose_phrase_;
}

void Unit_Matvey::startBattle(){
    winsCnt = 0;
    lossCnt = 0;
    oLog.clear();
    pLog.clear();
}

Choice Unit_Matvey::makeChoice(){
    if(oLog.size() == 0){  //first play
        currPlay = Choice::ROCK;
        return currPlay;
    }

    if(oLog[oLog.size() - 1] == 1){
        currPlay = pLog[pLog.size() - 1];
    } else {
        Choice ch = pLog[pLog.size() - 1];
        currPlay = ref[std::find(ref.begin(), ref.end(), ch) - ref.begin() + 1];
        // if (ch == Choice::ROCK){
        //     currPlay = Choice::PAPER;
        // }
        // if (ch == Choice::PAPER){
        //     currPlay = Choice::SCISSORS;
        // }
        // if (ch = Choice::SCISSORS){
        //     currPlay = Choice::ROCK;
        // }
    }

    return currPlay;
    
    
}

void Unit_Matvey::getResult(Choice ch){
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


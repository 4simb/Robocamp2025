#include <iostream>
#include <vector>
#include <unordered_map>

#include "test.h"

const int ROUNDS_AMOUNT = 5;
const int DRAW_MAX = 10;

int main(int argc, char *argv[]) {
    std::unordered_map<Choice, std::string> textChoice;
    textChoice[Choice::PAPER] = " PAPERS ";
    textChoice[Choice::ROCK] = "  ROCK  ";
    textChoice[Choice::SCISSORS] = "SCISSORS";

    std::vector<BaseUnit *> gladiators;

    gladiators.push_back(new Test1("Test1"));
    gladiators.push_back(new Test2("Test2"));
    // gladiators.push_back(new Test1("Test3"));
    // gladiators.push_back(new Test2("Test4"));
    // gladiators.push_back(new Test1("Test5"));

    while (gladiators.size() > 1) {
        for (int i = 1; i < gladiators.size(); i += 2) {
            std::cin.get();
            int firstWins = 0;
            int secondWins = 0;
            int draws = 0;
            gladiators[i - 1]->StartBattle(ROUNDS_AMOUNT);
            gladiators[i]->StartBattle(ROUNDS_AMOUNT);

            std::cout << "\033[1;34m";
            std::cout << "!!! " << gladiators[i - 1]->GetName() << " VS "
                      << gladiators[i]->GetName() << " !!!\n";
            std::cout << "\033[0m";
            std::cin.get();

            while (firstWins < ROUNDS_AMOUNT && secondWins < ROUNDS_AMOUNT &&
                   draws < DRAW_MAX) {
                Choice choiseFirst = gladiators[i - 1]->MakeChoice();
                Choice choiseSecond = gladiators[i]->MakeChoice();
                gladiators[i - 1]->SetResult(choiseSecond);
                gladiators[i]->SetResult(choiseFirst);
                if (choiseFirst == choiseSecond) {
                    draws++;

                    std::cout << "\033[1;33m";
                    std::cout << textChoice[choiseFirst];
                    std::cout << "\033[0m";

                    std::cout << "\t - \t";

                    std::cout << "\033[1;33m";
                    std::cout << textChoice[choiseSecond] << '\n';
                    std::cout << "\033[0m";
                } else if (choiseFirst - choiseSecond == 1 ||
                           choiseFirst - choiseSecond == -2) {
                    firstWins++;
                    draws = 0;

                    std::cout << "\033[1;32m";
                    std::cout << textChoice[choiseFirst];
                    std::cout << "\033[0m";

                    std::cout << "\t - \t";

                    std::cout << "\033[1;31m";
                    std::cout << textChoice[choiseSecond] << '\n';
                    std::cout << "\033[0m";
                } else {
                    secondWins++;
                    draws = 0;

                    std::cout << "\033[1;31m";
                    std::cout << textChoice[choiseFirst];
                    std::cout << "\033[0m";

                    std::cout << "\t - \t";

                    std::cout << "\033[1;32m";
                    std::cout << textChoice[choiseSecond] << '\n';
                    std::cout << "\033[0m";
                }
            }
            if (firstWins == ROUNDS_AMOUNT) {
                std::cout << "\033[1;32m\t";
                std::cout << firstWins;
                std::cout << "\033[0m";

                std::cout << "\t - \t";

                std::cout << "\033[1;31m";
                std::cout << secondWins << '\n';
                std::cout << "\033[0m";

                std::cout << "\033[1;34m";
                std::cout << gladiators[i - 1]->GetName()
                          << " wins:" << gladiators[i - 1]->GetWinPhrase()
                          << '\n';
                std::cout << gladiators[i]->GetName()
                          << " looses:" << gladiators[i]->GetLosePhrase()
                          << '\n';
                std::cout << "\033[0m";

                gladiators.erase(gladiators.begin() + i);
                --i;
            } else if (secondWins == ROUNDS_AMOUNT) {
                std::cout << "\033[1;31m\t";
                std::cout << firstWins;
                std::cout << "\033[0m";

                std::cout << "\t - \t";

                std::cout << "\033[1;32m";
                std::cout << secondWins << '\n';
                std::cout << "\033[0m";

                std::cout << "\033[1;34m";
                std::cout << gladiators[i]->GetName()
                          << " WINS: " << gladiators[i]->GetWinPhrase() << '\n';
                std::cout << gladiators[i - 1]->GetName()
                          << " LOOSES: " << gladiators[i - 1]->GetLosePhrase()
                          << '\n';
                gladiators.erase(gladiators.begin() + i - 1);
                --i;
                std::cout << "\033[0m";
            } else {
                std::cout << "\033[1;34m";
                std::cout << "No one wants to fight seriously... Both players "
                             "terminated!!!\n";
                std::cout << "\033[0m";
                gladiators.erase(gladiators.begin() + i);
                gladiators.erase(gladiators.begin() + i - 1);
                i -= 2;
            }
        }
    }

    std::cout << "\033[1;34m";
    if(gladiators.size() == 1){
        std::cout << "\nTHE GLADIATOR IS: " << "\033[1;32m" << gladiators[0]->GetName() << "\033[1;34m" << "!!!!!\n";
        std::cout << gladiators[0]->GetName() << " says - \"\033[1;32m" << gladiators[0]->GetWinPhrase() << "\033[1;34m\"";
    }

    return 0;
}
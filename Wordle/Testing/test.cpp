#include <iostream>
#include <algorithm>
#include <string>

int main()
{
    bool done = false;
    std::string key = "robot";
    std::string input;
    std::string score = "-----";
    //do {
    std::cout << "enter guess: ";
    std::cin >> input;

    std::cout << "key: " << key << std::endl;
    std::cout << "guess: " << input << std::endl;
    std::cout << "score: " << score << std::endl;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // r o b o t
            // m o b o o
            // - + - - -
            if (key[i] == input[j] && j == i) {
                score[i] = '+';
            }
        }
        //done = true;
    }
    //} while (done == false);
    std::cout << score << std::endl;
}

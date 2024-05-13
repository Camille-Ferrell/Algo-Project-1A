#include <iostream>
#include "code.h"

using namespace std;

int main() {
    code mastermind(0, 0);

    srand(time(0));

    mastermind.readInputs();
    int codeLength = mastermind.getLength();
    int codeRange = mastermind.getRange();

    vector<int> secretCode = mastermind.makeSequence(codeLength, codeRange);

    bool Answer = true;

    for (int attempts = 2; attempts >= 1; attempts--) {
        cout << "You are on attempt number " << attempts << endl;
        vector<int> Guess = mastermind.getSequence(codeLength);

        if (secretCode == Guess) {
            Answer = false;
            break;
        }

        int numCorrect = mastermind.checkCorrect(secretCode, Guess, codeLength);
        int numIncorrect = mastermind.checkIncorrect(secretCode, Guess, codeLength);
        cout << "You got " << numCorrect << " answers correct and " << numIncorrect << " answers incorrect" << endl;
    }

    if (Answer == false) {
        cout << "Good job, You Found the Answer!!";
    }
    if (Answer == true) {
        cout << "You have run out of attempts. The correct sequence was: ";
        for (int i : secretCode) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}

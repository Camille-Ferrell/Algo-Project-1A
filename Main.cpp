#include "Code.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
    srand(time(NULL));
    int n, m;
    cout << "Enter the code length: ";
    cin >> n;
    cout << "Enter the range of digits: ";
    cin >> m;

    Code secret_code(n, m);
    secret_code.initialize_randomly();
    secret_code.print_secret_code();

    cout << "You have 10 attempts to guess the code." << endl;

    for (int attempt = 1; attempt <= 10; ++attempt) {
        cout << "Attempt " << attempt << ": Enter your guess of length " << n << ": ";
        vector<int> guess(n);
        for (int i = 0; i < n; ++i) {
            cin >> guess[i];
        }

        int correct = secret_code.check_correct(guess);
        int incorrect = secret_code.check_incorrect(guess);
        cout << "Correct: " << correct << " Incorrect: " << incorrect << endl;

        if (correct == n) {
            cout << "Congratulations! You guessed the code correctly!" << endl;
            return 0;
        }
    }

    cout << "Sorry, you did not guess the code within 10 attempts. The correct code was: ";
    secret_code.print_secret_code();

    return 0;
}

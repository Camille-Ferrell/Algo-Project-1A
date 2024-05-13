#include "Code.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
    
    srand(time(NULL)); // Random Time Seed

    // Obtaining Length (n) and Range (m)
    int n, m;
    cout << "Enter the code length: ";
    cin >> n;
    cout << "Enter the range of digits: ";
    cin >> m;

    // Instance of class Code called secret_code
    Code secret_code(n, m);
    secret_code.initialize_randomly();
    secret_code.print_secret_code();

    cout << "You have 10 attempts to guess the code." << endl;

    // Loop to store the guess of length (n) and tracking the attempts
    for (int attempt = 1; attempt <= 10; ++attempt) {
        cout << "Attempt " << attempt << ": Enter your guess of length " << n << ": ";

        vector<int> guess(n);

        for (int i = 0; i < n; ++i) {
            cin >> guess[i];
        }

        // Returns the # of correct answers
        int correct = secret_code.check_correct(guess);

        // Returns the # of incorrect answers
        int incorrect = secret_code.check_incorrect(guess);

        cout << "Correct: " << correct << " Incorrect: " << incorrect << endl;

        // If the # of correct matches the Length of the SecretCode 
        // Game Won
        if (correct == n) {
            cout << "Congratulations! You guessed the code correctly!" << endl;
            return 0;
        }
    }

    // After running out of attemps Game Over
    cout << "Sorry, you did not guess the code within 10 attempts. The correct code was: ";
    secret_code.print_secret_code();

    return 0;
}

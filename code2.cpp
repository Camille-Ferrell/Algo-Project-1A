#include "code.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Constructor
code::code(int m, int n) {
    length = n;
    range = m;
}

// Getter for code length
int code::getLength() const {
    return length;
}

// Getter for code range
int code::getRange() const {
    return range;
}

// Method to read inputs for code length and range
void code::readInputs() {
    cout << "Please Enter the Desired Code Length: ";
    cin >> length;
    cout << "Please Enter the Desired Range of Digits: ";
    cin >> range;
}

// Method to generate a random sequence as the secret code
vector<int> code::makeSequence(int n, int m) {
    vector<int> Sequence;

    // Generate random sequence
    for (int i = 0; i < n; i++) {
        int temp = rand() % m; // from range 0 to m - 1
        Sequence.push_back(temp);
    }

    // Save the secret code internally
    secretCode = Sequence;

    return Sequence;
}

// Method to get a sequence from the user as their guess
vector<int> code::getSequence(int n) {
    vector<int> guess(n);
    cout << "Please Enter Your Guess of the Code: \n";

    int temp;

    // Get user input for the guess
    for (int i = 0; i < n; i++) {
        cin >> temp;
        guess[i] = temp;
    }
    return guess;
}

// Method to check how many digits in the guess are correct
int code::checkCorrect(vector<int> Guess) {
    int correct = 0;

    // Compare each digit of the guess with the corresponding digit of the secret code
    for (int i = 0; i < length; i++) {
        if (secretCode[i] == Guess[i]) {
            correct++;
        }
    }

    return correct;
}

// Method to check how many digits in the guess are incorrect
int code::checkIncorrect(vector<int> Guess) {
    int incorrect = 0;

    // Compare each digit of the guess with the corresponding digit of the secret code
    for (int i = 0; i < length; i++) {
        if (secretCode[i] != Guess[i]) {
            incorrect++;
        }
    }

    return incorrect;
}


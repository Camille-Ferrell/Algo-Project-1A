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

// Get Length from Private
int code::getLength() const {
    return length;
}

int code::getRange() const {
    return range;
}

// Read input from user
void code::readInputs() {
    cout << "Please Enter the Desired Code Length: ";
    cin >> length;
    cout << "Please Enter the Desired Range of Digits: ";
    cin >> range;
}

// make the random sequence and use random time seed later
vector<int> code::makeSequence(int n, int m) {
    vector<int> Sequence;

    for (int i = 0; i < n; i++) {
        int temp = rand() % m; // from range 0 to m - 1
        Sequence.push_back(temp);
    }
    return Sequence;
}

// Obtain the guess from the user
vector<int> code::getSequence(int n) {
    vector<int> guess(n);
    cout << "Please Enter Your Guess of the Code: \n";

    int temp;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        guess[i] = temp;
    }
    return guess;
}

// Check if secretCode is equal to Guess at same index
// If it is, add 1 to correct & returns # of correct
int code::checkCorrect(vector<int> Sequence, vector<int> Guess, int n) {
    int correct = 0;

    for (int i = 0; i < n; i++) {
        if (Sequence[i] == Guess[i]) {
            correct++;
        }
    }

    return correct;
}

// Check if secretCode is NOT equal to Guess at same index
// If it is incorrect, add 1 to coutner & returns # of incorrect
int code::checkIncorrect(vector<int> Sequence, vector<int> Guess, int n) {
    int incorrect = 0;

    for (int i = 0; i < n; i++) {
        if (Sequence[i] != Guess[i]) {
            incorrect++;
        }
    }

    return incorrect;
}

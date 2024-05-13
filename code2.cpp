#include "code.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

code::code(int m, int n) {
    length = n;
    range = m;
}

int code::getLength() const {
    return length;
}

int code::getRange() const {
    return range;
}

void code::readInputs() {
    cout << "Please Enter the Desired Code Length: ";
    cin >> length;
    cout << "Please Enter the Desired Range of Digits: ";
    cin >> range;
}

vector<int> code::makeSequence(int n, int m) {
    vector<int> Sequence;

    for (int i = 0; i < n; i++) {
        int temp = rand() % m; // from range 0 to m - 1
        Sequence.push_back(temp);
    }
    return Sequence;
}

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

int code::checkCorrect(vector<int> Sequence, vector<int> Guess, int n) {
    int correct = 0;

    for (int i = 0; i < n; i++) {
        if (Sequence[i] == Guess[i]) {
            correct++;
        }
    }

    return correct;
}

int code::checkIncorrect(vector<int> Sequence, vector<int> Guess, int n) {
    int incorrect = 0;

    for (int i = 0; i < n; i++) {
        if (Sequence[i] != Guess[i]) {
            incorrect++;
        }
    }

    return incorrect;
}

#include "Code.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Constructor 1
Code::Code(int n, int m) {
    this->n = n; // Getting Private Members
    this->m = m;
}

void Code::initialize_randomly() {
    
    secret_code.clear();

    // Loop to create n length
    for (int i = 0; i < n; ++i) {

        // Randomly Generate Number in M Range
        secret_code.push_back(rand() % m);
    }
}

// testing github

// Check if value in index i is equal for guess and secret_code
// Returns # of correct answers
int Code::check_correct(const vector<int>& guess) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (guess[i] == secret_code[i]) {
            count++;
        }
    }
    return count;
}

// Check if value in index i is equal for guess and secret_code
// Returns # of incorrect answers
int Code::check_incorrect(const vector<int>& guess) {
    int count = 0;
    vector<int> secret_copy = secret_code;

    // I DONT KNOW WHAT THIS IS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // Maybe can just use same thin as line 33 to 37 just with a != on line 35
    for (int i = 0; i < n; ++i) {
        auto it = find(secret_copy.begin(), secret_copy.end(), guess[i]);
        if (it != secret_copy.end()) {
            count++;
            secret_copy.erase(it);
        }
    }
    count -= check_correct(guess);
    return count;
}

// Print Secret_Code
void Code::print_secret_code() {
    cout << "Secret Code: ";

    // Iterate through vector and return digit
    for (int digit : secret_code) {
        cout << digit << " ";
    }

    cout << endl;

}

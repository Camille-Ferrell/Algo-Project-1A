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
    int count = 0; // initialize a counter to keep track of the number of correct digits in the wrong location
    vector<int> secret_copy = secret_code; // copy to avoid changing the actual secret code

    for (int i = 0; i < n; ++i) { // loop through each digit of the guess 
        auto it = find(secret_copy.begin(), secret_copy.end(), guess[i]); // search for the current guess digit in the secret code
        if (it != secret_copy.end()) { // if the guess digit is found in the secret code
            count++; // increment the count of correct digits in the wrong location
            secret_copy.erase(it); // remove the matched digit from the copy of the secret code
        }
    }
    count -= check_correct(guess); // subtract the count of correct digits in the correct location
    return count; // return the amount of correct digits in the incorrect location
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

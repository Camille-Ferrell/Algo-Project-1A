/*
Project 1A

This file contains the declarations of the functions for the game
It creates the Code class and the private and public member functions

*/

#ifndef CODE_H
#define CODE_H

#include <vector>

using namespace std; 

class Code {
private:
    vector<int> secret_code;
    int n; // length
    int m; // range

public:
    Code(int n, int m); // constructor

    void initialize_randomly(); // the function that initializes the secret code

    int check_correct(const vector<int>& guess); // check correct function passing only the guess as a parameter

    int check_incorrect(const vector<int>& guess); // check incorrect function

    void print_secret_code(); // function to print the secret code
};

#endif // CODE_H

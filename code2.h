#ifndef CODE_H
#define CODE_H

#include <vector>

using namespace std;

class code {
public:
    // Constructor
    code(int m, int n);

    // Method to generate a random sequence given length (n) and range (m)
    vector<int> makeSequence(int n, int m);

    // Method to read input sequence guess from the user
    vector<int> getSequence(int n);

    // Method to check how many digits in the guess are correct
    int checkCorrect(vector<int> Guess);

    // Method to check how many digits in the guess are incorrect
    int checkIncorrect(vector<int> Guess);

    // Method to read input from user for length and range
    void readInputs();

    // Getter for code length
    int getLength() const;

    // Getter for code range
    int getRange() const;

private:
    int length; // Code Length (n)
    int range; // Code Range (m)
    vector<int> secretCode; // Store the secret code to avoid passing it repeatedly
};

#endif // CODE_H


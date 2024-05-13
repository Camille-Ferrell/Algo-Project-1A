#ifndef CODE_H
#define CODE_H

#include <vector>

using namespace std;

class code {
public:

    // Constructor
    code(int m, int n);

    vector<int> makeSequence(int n, int m); // Generates Random Sequence Given Length (n) and Range (m)
    vector<int> getSequence(int n); // Reads Input Sequence Guess from the user
    int checkCorrect(vector<int> Sequence, vector<int> Guess, int n); // Check correct
    int checkIncorrect(vector<int> Sequence, vector<int> Guess, int n); // Check incorrect
    
    void readInputs(); // Read Input from User for Length and Range

    // Get from Private
    int getLength() const;
    int getRange() const;

private:
    int length; // Code Length (n)
    int range; // Code Range (m)
};

#endif // CODE_H

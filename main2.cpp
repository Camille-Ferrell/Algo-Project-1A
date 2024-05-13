// Errors found right now: Might not be generating from range 0 to M -1

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

class code{
    public: 
        code(int m, int n); // Constructor
        
        vector<int> makeSequence(int n, int m); // Generates Random Sequence
        vector<int> getSequence(int n); // Read input Sequence from the User
        int checkCorrect(vector<int> Sequence, vector<int> Guess, int n); 
        int checkIncorrect(vector<int> Sequence, vector<int> Guess, int n);

        void readInputs();
        // void writeSequence() const;  Return Correct Answer if not found within 10 tries

        // Get from Private
        int getLength() const; 
        int getRange() const;

    private:
        int length; // Code Length (n)
        int range; // Range of Digits (m)
};

int main(){
    // create instance of class code
    code mastermind(0,0);

    srand(time(0));
    
    // get inputs for length and range
    mastermind.readInputs();
    int codeLength = mastermind.getLength();
    int codeRange = mastermind.getRange();

    // Generate the secret code
    vector<int> secretCode = mastermind.makeSequence(codeLength, codeRange);
    
    // Loop to track attemps
    // Should be less than 10

    bool Answer = true;

    for (int attempts = 2; attempts >= 1; attempts--){
        cout << "You are on attempt number " << attempts << endl;
        vector<int> Guess = mastermind.getSequence(codeLength);

        // Check if sequence found
        if (secretCode == Guess){ 
            Answer = false;
            break;
        }

        // Return the number of correct and incorrect
        int numCorrect = mastermind.checkCorrect(secretCode, Guess, codeLength);
        int numIncorrect = mastermind.checkIncorrect(secretCode, Guess, codeLength);
        cout << "You got " << numCorrect << " answers correct and " << numIncorrect << " answers incorrect" << endl;
    }

    if (Answer == false){
        cout << "Good job, You Found the Answer!!";
    }
    if (Answer == true){
        // mastermind.writeSequence();
        cout << "You have run out of attempts. The correct sequence was: ";
        for (int i : secretCode){
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}

code::code(int m, int n){
    length = n;
    range = m;
}

int code::getLength() const{
    return length;
}

int code::getRange() const{
    return range;
}

void code::readInputs(){
    cout << "Please Enter the Desired Code Length: ";
    cin >> length;
    cout << "Please Enter the Desired Range of Digits: ";
    cin >> range;
}

vector<int> code::makeSequence(int n, int m){

    vector<int> Sequence;

    for (int i = 0; i < n; i++){
        int temp = rand() % (m); //from range 0 to m - 1
        Sequence.push_back(temp);
    }
    return Sequence;
}

vector<int> code::getSequence(int n){
    vector<int> guess(n);
    cout << "Please Enter Your Guess of the Code: \n";

    int temp;

    for (int i = 0; i < n; i++){
        cin >> temp;
        guess[i] = temp;
    }
    return guess;
}

int code::checkCorrect(vector<int> Sequence, vector<int> Guess, int n){

    //int temp;
    int correct;

    for (int i = 0; i < n; i++){
        cout << Sequence[i] << " " << Guess[i] << endl; // Testing

        if (Sequence[i] == Guess[i]){
            correct++;
        }
    }

    return correct;
}

int code::checkIncorrect(vector<int> Sequence, vector<int> Guess, int n){

    int incorrect;

    for (int i = 0; i < n; i++){
        if (Sequence[i] != Guess[i]){
            incorrect++;
        }
    }

    return incorrect;
}

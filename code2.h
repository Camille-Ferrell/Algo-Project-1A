#ifndef CODE_H
#define CODE_H

#include <vector>

using namespace std;

class code {
public:
    code(int m, int n);

    vector<int> makeSequence(int n, int m);
    vector<int> getSequence(int n);
    int checkCorrect(std::vector<int> Sequence, std::vector<int> Guess, int n);
    int checkIncorrect(std::vector<int> Sequence, std::vector<int> Guess, int n);

    void readInputs();
    int getLength() const;
    int getRange() const;

private:
    int length;
    int range;
};

#endif // CODE_H

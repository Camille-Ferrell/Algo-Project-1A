#ifndef CODE_H
#define CODE_H

#include <vector>

class Code {
private:
    vector<int> secret_code;
    int n;
    int m;
public:
    Code(int n, int m);

    void initialize_randomly();

    int check_correct(const std::vector<int>& guess);

    int check_incorrect(const std::vector<int>& guess);

    void print_secret_code();
};

#endif // CODE_H

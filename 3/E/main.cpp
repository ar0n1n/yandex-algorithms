#include <iostream>
#include <unordered_set>
#include <fstream>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    bool digits[10] = { false };
    unordered_set<int> s;
    int num;
    string input;

    for (int i = 0; i < 3; ++i) {
        in >> num;
        digits[num] = true;
    }

    in >> input;
    if (!input.compare("0"))
        out << digits[0];
    else {
        for (char c : input) {
            if (!digits[c - '0'])
                s.insert(c - '0');
        }
        out << s.size();
    }
}
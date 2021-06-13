#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    unordered_map<string, int> hash;
    string word;

    while (in >> word) {
        out << hash[word] << ' ';
        ++hash[word];
    }
}


#include <iostream>
#include <unordered_set>
#include <fstream>

using namespace std;

int main() {
    unordered_set<string> hash;
    string word;

    ifstream in("input.txt");
    ofstream out("output.txt");

    while (in >> word)
        hash.insert(word);

    out << hash.size();
}
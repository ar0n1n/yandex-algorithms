#include <iostream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

int findStress(string &word) {
    int stress = -1;

    for (int i = 0; i < word.size(); ++i) {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            if (stress != -1) return -1;
            stress = i;
        }
    }
    return stress;
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n, ans(0);
    string word;
    unordered_map<string, unordered_set<int>> hash;

    in >> n;
    for (int i = 0; i < n; ++i) {
        in >> word;
        int stress = findStress(word);
        word[stress] += 32;
        hash[word].insert(stress);
    }

    while (in >> word) {
        int stress = findStress(word);
        if (stress == -1) ++ans;
        else {
            word[stress] += 32;
            if (hash.find(word) != hash.end() && !hash[word].count(stress))
                ++ans;
        }
    }

    out << ans;
}
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;

int checkChar(char &c, bool wordStart, bool isRegSensitive,
              bool canStartWithDigit) {
    if (isdigit(c)) {
        if (wordStart && !canStartWithDigit)
            return -1;
        return 1;
    }
    else if (isalpha(c)) {
        if (!isRegSensitive) c = tolower(c);
        return 1;
    }
    else return c == '_';
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n;
    pair<int, size_t> max = make_pair(1000, 0);
    string input, ans;
    bool isRegSensitive, canStartWithDigit, wordStart, skipWord;
    unordered_set<string> khash;
    unordered_map<string, pair<int, size_t>> ihash;

    in >> n >> input;
    isRegSensitive = !(input.compare("yes"));
    in >> input;
    canStartWithDigit = !(input.compare("yes"));

    for (int i = 0; i < n; ++i) {
        in >> input;
        if (!isRegSensitive) {
            for (char &c : input) c = tolower(c);
        }
        khash.insert(input);
    }

    while(in >> input) {
        vector<string> identifiers(1);
        wordStart = true; skipWord = false;
        for (int i = 0; i < input.size(); ++i) {
            int check = checkChar(input[i], wordStart, isRegSensitive, canStartWithDigit);
            if (check == -1)
                skipWord = true;
            else if (check == 1) {
                if (!skipWord) {
                    identifiers.back().append(1, input[i]);
                    wordStart = false;
                }
            }
            else if (!wordStart) {
                wordStart = true; skipWord = false;
                if (!identifiers.back().empty());
                identifiers.push_back("");
            }
            else skipWord = false;
        }
        for (string identifier : identifiers) {
            if (!identifier.empty() && !khash.count(identifier)
                && !(identifier.size() == 1 && isdigit(identifier[0]))) {
                ++ihash[identifier].second;
                if (ihash[identifier].second == 1)
                    ihash[identifier].first = ihash.size();
                if (ihash[identifier].second > max.second
                    || (ihash[identifier].second == max.second &&  ihash[identifier].first < max.first)) {
                    max = ihash[identifier];
                    ans = identifier;
                }
            }
        }
    }

    out << ans;
}
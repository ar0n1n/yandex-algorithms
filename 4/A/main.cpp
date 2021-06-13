#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<string, string> hash;
    string target, word1, word2;
    int n;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> word1 >> word2;
        hash[word1] = word2;
        hash[word2] = word1;
    }

    cin >> target;
    cout << hash[target];
}


#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    unordered_map<string, int> hash;
    int n, m;
    string lang;
    vector<string> allLangs;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        for (int j = 0; j < m; ++j) {
            cin >> lang;
            hash[lang] += 1;
            if (hash[lang] == n)
                allLangs.push_back(lang);
        }
    }

    cout << allLangs.size() << endl;
    for (string lang : allLangs)
        cout << lang << endl;

    cout << hash.size() << endl;
    for (auto lang : hash)
        cout << lang.first << endl;
}
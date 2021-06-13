#include <iostream>
#include <unordered_set>
#include <fstream>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    unordered_multiset<string> hash1;
    unordered_set<string> hash2;
    string genom;
    int ans(0);
    bool first = true;

    while (getline(in, genom)) {
        int n = genom.size() - 1;
        for (int i = 0; i < n; ++i) {
            string base = genom.substr(i, 2);
            if (first)
                hash1.insert(base);
            else {
                if (hash2.insert(base).second)
                    ans += hash1.count(genom.substr(i, 2));
            }
        }
        first = false;
    }
    out << ans;
}
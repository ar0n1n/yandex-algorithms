#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>

using namespace std;


int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    array<int,123> hash{}, comp{};
    int g, s, ans(0);
    string word, str;

    in >> g >> s >> word >> str;
    for (char c : word) ++hash[c];
    for (int i = 0; i < s; ++i) {
        ++comp[str[i]];
        if (i >= g) --comp[str[i-g]];
        if (i >= g - 1 && comp == hash) ++ans;
    }
    out << ans;
}

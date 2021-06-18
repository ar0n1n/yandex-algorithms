#include <iostream>
#include <fstream>
using namespace std;

int main() {
    size_t k, len, l = 0, ans = 0;
    string str;

    ifstream in("input.txt");
    ofstream out("output.txt");

    in >> k >> str;

    for (int r = 0; r < str.size(); ++r) {
        len = r - l;
        if (len < k) continue;
        if (str[r] != str[l + len % k]) l = r - k + 1;
        else ans += len - k + 1;
    }

    out << ans;
}
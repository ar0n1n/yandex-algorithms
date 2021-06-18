#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int64_t w, h, n;
    in >> w >> h >> n;

    int64_t l = 0, r = max(w, h) * n, m;

    while (l < r) {
        m = (l + r) / 2;
        if ((m / w) * (m / h) >= n) r = m;
        else l = m + 1;
    }

    out << l;
}


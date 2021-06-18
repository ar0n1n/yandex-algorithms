#include <iostream>

using namespace std;

int main() {
    uint64_t N, x, y;
    cin >> N >> x >> y;

    uint64_t l = 0, r = N * min(x,y), m;
    while (l < r) {
        m = (l + r) / 2;
        if (m / x + m / y >= N - 1) r = m;
        else l = m + 1;
    }

    cout << l + min(x,y);
}
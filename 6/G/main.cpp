#include <iostream>

using namespace std;

int main() {
    uint64_t h, w, t, sqe, sqi;
    cin >> h >> w >> t;

    sqe = h * w;
    uint64_t l = 0, r = min(h, w) / 2, m;
    while (l < r) {
        m = (l + r + 1) / 2;
        sqi = (w - 2 * m) * (h - 2 * m);
        if (sqe - sqi <= t) l = m;
        else r = m - 1;
    }

    cout << l;
}
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    uint64_t n, a, b, w, h;
    cin >> n >> a >> b >> w >> h;

    uint64_t l = 0, r = max(w, h), m, mc;
    while (l < r) {
        m = (l + r + 1) / 2;
        mc = max((w / (a + 2 * m)) * (h / (b + 2 * m)),
                 (h / (a + 2 * m)) * (w / (b + 2 * m)));
        if (mc < n) r = m - 1;
        else l = m;
    }

    cout << l;
}
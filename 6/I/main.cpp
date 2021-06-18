#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int> &v, int m, int R, int C) {
    int r = 0;
    int n = v.size() - C + 1;

    for (int i = 0; i < n; ) {
        if (v[i + C - 1] - v[i] <= m) {
            r += 1; i += C;
        }
        else ++i;
        if (r >= R) return true;
    }
    return false;
}

int main() {
    int N, R, C;
    cin >> N >> R >> C;

    vector<int> v(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());

    int l = 0, r = v.back() - v.front(), m;
    while (l < r) {
        m = (l + r) / 2;
        if (check(v, m, R, C)) r = m;
        else l = m + 1;
    }

    cout << l;
}
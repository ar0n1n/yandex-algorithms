#include <iostream>
#include <vector>

using namespace std;

int find2L(vector<int> &a, vector<int> &b, int n) {
    int la = 0, lb = 0, ra = n - 1, rb = n - 1, ma, mb;

    while (la < ra) {
        ma = (ra + la) / 2;
        mb = (rb + lb) / 2;
        if (a[ma] >= b[mb]) {
            ra = ma;
            lb = mb + (rb - lb) % 2;
        }
        else {
            rb = mb;
            la = ma + (ra - la) % 2;
        }
    }

    return min(a[la], b[lb]);
}

int main() {
    int N, L;
    cin >> N >> L;

    vector<vector<int>> v(N, vector<int>(L));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < L; ++j)
            cin >> v[i][j];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j)
            cout << find2L(v[i], v[j], L) << endl;
    }
}
#include <iostream>
#include <vector>

using namespace std;

bool check(vector<int> &v, uint64_t m, int K) {
    int k = 0;

    for (int i = v.size() - 1; i >= 0; --i) {
        k += v[i] / m;
        if (k >= K) return true;
    }

    return false;
}


int main() {
    int N, K;
    cin >> N >> K;

    vector<int> v(N);
    uint64_t sum =  0;
    for (int i = 0; i < N; ++i) {
        cin >> v[i]; sum += v[i];
    }

    uint64_t l = 0, r = sum / K, m;
    while (l < r) {
        m = (l + r + 1) / 2;
        if (check(v, m, K)) l = m;
        else r = m - 1;
    }

    cout << l;
}


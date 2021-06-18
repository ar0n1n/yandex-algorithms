#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, x;

    scanf("%d", &n);
    int p[n][2];
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &p[i][0], &p[i][1]);
    }

    vector<int> prefix1(n);
    prefix1[0] = 0;
    for (int i = 1; i < n; ++i) {
        int diff = p[i][1] - p[i-1][1];
        if (diff > 0) prefix1[i] = prefix1[i-1] + diff;
        else prefix1[i] = prefix1[i-1];
    }
    vector<int> prefix2(n);
    prefix2[n - 1] = 0;
    for (int i = n - 2; i >= 0; --i) {
        int diff = p[i][1] - p[i+1][1];
        if (diff > 0) prefix2[i] = prefix2[i+1] + diff;
        else prefix2[i] = prefix2[i+1];
    }

    scanf("%d", &m);
    int dist[m][2];
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &dist[i][0], &dist[i][1]);
    }

    for (int i = 0; i < m; ++i) {
        int l = dist[i][0] - 1, r = dist[i][1] - 1;
        if (r > l) cout << (prefix1[r] - prefix1[l]) << endl;
        else cout << (prefix2[r] - prefix2[l]) << endl;
    }
}


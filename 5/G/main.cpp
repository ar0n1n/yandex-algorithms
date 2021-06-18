#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    long long int n, K;
    long long int ans = 0;

    in >> n >> K;

    vector<int> x(n);
    vector<pair<int,int>> v;
    long long int count[2] = {0};

    for (int i = 0; i < n; ++i) in >> x[i];
    sort(x.begin(), x.end());

    for (int i = 0, cnt = 0; i < n; ++i) {
        ++cnt;
        if (i == n - 1 || x[i] != x[i + 1]) {
            v.push_back(make_pair(x[i], cnt));
            cnt = 0;
        }
    }

    for (long long int i = 0, j = 1; i < v.size(); ++i) {
        while (j < v.size() && v[i].first >= (v[j].first + K - 1) / K) {
            ++count[0];
            count[1] += (v[j++].second > 1);
        }

        switch (v[i].second) {
            default: ans += 1;
            case 2: ans += 3 * count[0];
            case 1: ans += 3 * (count[1] + count[0] * (count[0] - 1));
        }

        if (i + 1 == j) ++j;
        else {
            --count[0];
            count[1] -= (v[i + 1].second > 1);
        }
    }
    out << ans << endl;

    return 0;
}
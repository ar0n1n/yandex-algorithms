#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    M *= 2;

    vector<pair<int,int>> v(M);
    for (int i = 0; i < M; i += 2) {
        cin >> v[i].first; v[i].second = -1;
        cin >> v[i+1].first; v[i+1].second = 1;
    }

    sort(v.begin(), v.end());

    int ans = 0, teachers = 0, prev_time = -1;
    for (const auto&[time, event] : v) {
        if (!teachers) ans += time - prev_time - 1;
        teachers -= event;
        prev_time = time;
    }
    ans += max(0, N - prev_time - 1);

    cout << ans << endl;
}

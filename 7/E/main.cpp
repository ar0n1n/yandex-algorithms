#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N, sh, sm, eh, em, ans = 0,
            count = 0, time_prev = 0, eod = 24 * 60;
    vector<pair<int,int>> v;

    in >> N;
    for (int i = 0; i < N; ++i) {
        in >> sh >> sm >> eh >> em;
        int start = sh * 60 + sm;
        int end = eh * 60 + em;
        if (start < end) {
            v.push_back(make_pair(start, -1));
            v.push_back(make_pair(end, 1));
        }
        else {
            v.push_back(make_pair(start, -1));
            v.push_back(make_pair(eod, 1));
            v.push_back(make_pair(0, -1));
            v.push_back(make_pair(end, 1));
        }
    }

    sort(v.begin(), v.end());

    for (const auto &[time, event] : v) {
        if (count == N) ans += time - time_prev;
        count -= event;
        time_prev = time;
    }

    out << ans << endl;
}
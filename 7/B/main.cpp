#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N, M, count = 0, p1, p2;
    in >> N >> M;
    map<int,int[3]> m;
    unordered_map<int,vector<int>> indices;
    vector<int> ans(M);

    for (int i = 0; i < N; ++i) {
        in >> p1 >> p2;
        m[min(p1,p2)][0] += 1; m[max(p1,p2)][2] += 1;
    }
    for (int i = 0; i < M; ++i) {
        in >> p1; m[p1][1] += 1;
        indices[p1].push_back(i);
    }

    for (const auto&[point, event] : m) {
        for (int i = 0; i < 3; ++i) {
            if (!event[i]) continue;
            if (i == 1) {
                for (int idx : indices[point])
                    ans[idx] = count;
            }
            else count -= event[i] * (i - 1);
        }
    }

    for (int i = 0; i < M; ++i)
        out << ans[i] << " ";
}

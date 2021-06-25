#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int M, N, t, z, y, ans;
    in >> M >> N;
    vector<pair<int,int>> v;
    vector<int> finished(N);

    for (int i = 0; i < N; ++i) {
        in >> t >> z >> y;
        int timer = 0, count = 0;
        while (count < M) {
            for (int j = 0; j < z && count < M; ++j) {
                timer += t; ++count;
                v.push_back(make_pair(timer,i));;
            }
            timer += y;
        }
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < M; ++i)
        finished[v[i].second] += 1;

    out << (!M ? 0 : v[M - 1].first) << endl;
    for (int i = 0; i < N; ++i)
        out << finished[i] << " ";
}
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N, D, vars_total = 0, j = 0;
    in >> N >> D;

    vector<int> v(N), ans(N);
    unordered_map<int,int> indices;
    unordered_set<int> vars;

    for (int i = 0; i < N; ++i) {
        in >> v[i]; indices[v[i]] = i;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < N; ++i) {
        while (j < i && v[i] - v[j] > D)
            vars.erase(ans[indices[v[j++]]]);
        int k = vars.size() == vars_total && i > 0 ? vars.size() : 1;
        for ( ; vars.count(k); ++k);
        vars.insert(k);
        ans[indices[v[i]]] = k;
        vars_total = max((size_t)vars_total, vars.size());
    }

    out << vars_total << endl;
    for (int i = 0; i < N; ++i)
        out << ans[i] << " ";
}


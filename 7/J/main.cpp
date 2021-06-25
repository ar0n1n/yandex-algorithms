#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct event {
    int z;
    int area;
    int type;
    int id;

    const bool operator< (const event &e) const {
        if (z != e.z) return z < e.z;
        else if (type != e.type) return type < e.type;
        else return id < e.id;
    }
};

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N, W, L, area, x1, y1, x2, y2;
    in >> N >> W >> L;
    N *= 2; area = W * L;

    vector<event> v(N);
    vector<bool> status(N / 2 + 1);
    for (int i = 0; i < N; i += 2) {
        event e1, e2;
        in >> x1 >> y1 >> e1.z >> x2 >> y2 >> e2.z;
        e1.type = 1; e2.type = -1;
        e1.id = e2.id = i / 2 + 1;
        e1.area = e2.area = (x2 - x1) * (y2 - y1);
        v[i] = e1; v[i + 1] = e2;
    }

    sort(v.begin(), v.end());

    int bh = -1, bc = N + 1, counter = 0;
    for (event &e : v) {
        area -= e.type * e.area;
        counter += e.type;
        if (!area && counter < bc) {
            bc = counter; bh = e.z;
        }
    }

    if (bh == -1) {
        out << "NO" << endl; return 0;
    }

    for (event &e : v) {
        area -= e.type * e.area;
        if (e.type == 1) status[e.id] = true;
        else status[e.id] = false;
        if (!area && e.z == bh) break;
    }

    out << "YES" << endl;
    out << bc << endl;
    for (int i = 1; i < status.size(); ++i) {
        if (status[i]) out << i << endl;
    }
}
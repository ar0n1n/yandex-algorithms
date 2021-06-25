#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct event {
    int time;
    int type;
    int id;

    const bool operator< (const event &e) const {
        if (time != e.time) return time < e.time;
        else if (type != e.type) return type < e.type;
        else return id < e.id;
    }
};

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N, K;
    in >> K;

    vector<bool> ans(K);
    for (int k = 0; k < K; ++k) {
        in >> N;
        N *= 2;
        vector<event> v(N);
        for (int i = 0; i < N; i += 2) {
            event e1, e2;
            in >> e1.time; e1.type = -1; e1.id = i;
            in >> e2.time; e2.type = 1; e2.id = i;
            v[i] = e1; v[i+1] = e2;
        }
        sort(v.begin(), v.end());

        if (v.front().time > 0 || v.back().time < 10000) {
            ans[k] = false; continue;
        }

        int time_prev = 0, counter = 0, timer = 0;
        unordered_map<int,bool> hash;
        for (event &e : v) {
            if (counter == 1 && e.time > time_prev) {
                for (auto &p : hash) p.second = true;
            }

            counter -= e.type;
            if (e.type == -1) {
                if (counter == 1 && e.time > time_prev) {
                    timer = 0; break;
                }
                hash[e.id] = false;
            }
            else {
                if (!hash[e.id]) {
                    timer = 0; break;
                }
                hash.erase(e.id);
                timer += e.time - time_prev;
                time_prev = e.time;
            }
        }
        ans[k] = (timer == 10000);
    }

    for (int i = 0; i < K; ++i) {
        out << (ans[i] ? "Accepted" : "Wrong Answer") << endl;
    }
}
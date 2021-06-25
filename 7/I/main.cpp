#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct event {
    int time;
    int city;
    int id;

    const bool operator< (const event &e) const {
        if (time != e.time) return time < e.time;
        else return city < e.city;
    }

    const bool operator> (const event &e) const {
        if (time != e.time) return time > e.time;
        else return city > e.city;
    }
};

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N, M;
    in >> N >> M;

    vector<priority_queue<int, vector<int>, greater<int>>> status(N + 1);
    vector<event> start;
    unordered_map<int, event> end;
    int counter = 0;

    for (int i = 0; i < M; ++i) {
        event e1, e2; int c1, h1, m1, c2, h2, m2; char c;
        in >> c1 >> h1 >> c >> m1;
        e1.time = h1 * 60 + m1;
        e1.city = c1; e1.id = i;
        in >> c2 >> h2 >> c >> m2;
        e2.time = h2 * 60 + m2;
        e2.city = c2; e2.id = i;
        start.push_back(e1); end[i] = e2;
    }

    sort(start.begin(), start.end());

    for (int i = 0; i < 3; ++i) {
        int timeadd = i * 60 * 24;
        for (auto st : start) {
            if (status[st.city].empty() ||
                status[st.city].top() > st.time + timeadd) {
                if (i == 2) {
                    counter = -1; break;
                }
                else {
                    counter += 1;
                    event dest = end[st.id];
                    status[dest.city].push(dest.time + timeadd
                                           + (dest.time < st.time ? 60 * 24 : 0));
                }
            }
            else {
                event dest = end[st.id];
                status[dest.city].push(dest.time + timeadd
                                       + (dest.time < st.time ? 60 * 24 : 0));
                status[st.city].pop();
            }
        }
    }

    out << counter;

}

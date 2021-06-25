#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct event {
    int time;
    int type;
    int customer;

    const bool operator< (const event &e) const {
        if (time != e.time) return time < e.time;
        else if (type != e.type) return type < e.type;
        else return customer < e.customer;
    }
};

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N;
    in >> N;

    vector<event> events;
    vector<bool> visitors(N);
    int count1 = 0, maxcount = 0, r1 = 5, r2 = 10;

    events.reserve(2 * N);
    for (int i = 0; i < N; ++i) {
        event e1, e2;
        in >> e1.time >> e2.time;
        if (e2.time - e1.time < 5) continue;
        e1.time += 5;
        e1.type = -1; e1.customer = i; events.push_back(e1);
        e2.type = 1; e2.customer = i; events.push_back(e2);
    }

    sort(events.begin(), events.end());

    for (int i = 0; i < events.size(); ++i) {
        if (events[i].type == -1) {
            visitors[events[i].customer] = true;
            ++count1;
        }
        else {
            visitors[events[i].customer] = false;
            --count1;
        }
        if (count1 > maxcount) {
            maxcount = count1;
            r1 = events[i].time - 5;
            r2 = events[i].time;
        }

        int count2 = 0;
        for (int j = i + 1; j < events.size(); ++j) {
            if (!visitors[events[j].customer] && events[j].type == -1)
                ++count2;
            if (events[j].time - events[i].time >= 5 &&
                count1 + count2 > maxcount) {
                maxcount = count1 + count2;
                r1 = events[i].time - 5; r2 = events[j].time - 5;
            }
            if (!visitors[events[j].customer] && events[j].type == 1)
                --count2;
        }
    }

    out << maxcount << " " << r1 << " " << r2;
}

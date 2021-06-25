#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct event {
    int date;
    int type;
    int person;

    const bool operator< (const event &e) const {
        if (date != e.date) return date < e.date;
        else if (type != e.type) return type < e.type;
        else return person < e.person;
    }
};

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N; in >> N;
    vector<event> v;
    unordered_set<int> people;
    vector<unordered_set<int>> ans;
    int d1, m1, y1, d2, m2, y2, count = 0, maxcount = 0;

    for (int i = 1; i <= N; ++i) {
        event e1, e2;
        in >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;
        e1.date = (y1 + 18) * 12 * 31 + m1 * 31 + d1;
        e1.type = -1; e1.person = i;
        e2.date = y2 * 12 * 31 + m2 * 31 + d2;
        e2.type = 1; e2.person = i;
        if (e2.date - e1.date > 0) {
            e2.date = min(e2.date, e1.date + 62 * 12 * 31) - 1;
            v.push_back(e1); v.push_back(e2);
        }
    }
    sort(v.begin(), v.end());

    for (event &e : v) {
        if (e.type == -1) {
            if (people.empty()) maxcount = 0;
            people.insert(e.person);
            ++count;
        }
        else {
            if (count >= maxcount)
                ans.push_back(people);
            people.erase(e.person);
            maxcount = count--;
        }
    }

    if (ans.empty())
        out << 0 << endl;

    for (int i = 0; i < ans.size(); ++i) {
        for (int id : ans[i])
            out << id << " ";
        out << endl;
    }
}
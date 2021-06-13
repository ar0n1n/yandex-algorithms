#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

void printSet(set<int> &s) {
    int size = s.size();

    cout << size << endl;
    for (int num : s) {
        cout << num;
        if (--size)
            cout << ' ';
    }
    cout << endl;
}

int main() {
    unordered_map<int,int> hash;
    int n, m, num;
    set<int> a, b, both;

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> num; hash[num] += 1;
    }
    for (int i = 0; i < m; ++i) {
        cin >> num; hash[num] -= 1;
    }
    for (auto p : hash) {
        if (p.second == 0)
            both.insert(p.first);
        else if (p.second == 1)
            a.insert(p.first);
        else
            b.insert(p.first);
    }

    printSet(both);
    printSet(a);
    printSet(b);
}
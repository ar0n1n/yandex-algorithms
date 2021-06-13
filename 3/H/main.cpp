#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    unordered_set<int> hash;
    int n, x, y;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        hash.insert(x);
    }

    cout << hash.size() << endl;
}


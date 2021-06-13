#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    unordered_set<int> hash;
    int n, ahead, behind;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ahead >> behind;
        if (ahead >= 0 && behind >= 0
            && ahead + behind == n - 1)
            hash.insert(ahead);
    }

    cout << hash.size() << endl;
}

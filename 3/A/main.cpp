#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> s;
    int num;

    while (cin >> num)
        s.insert(num);

    cout << s.size() << endl;
}


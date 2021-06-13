#include <iostream>
#include <unordered_set>
#include <set>
#include <sstream>
#include <fstream>

using namespace std;

int main() {
    unordered_set<int> hash;
    set<int> s;
    string line, ans;
    int num;
    bool first = true;

    ifstream in("input.txt");
    ofstream out("output.txt");

    while (getline(in, line)) {
        stringstream ss(line);
        while (ss >> num) {
            if (first)
                hash.insert(num);
            else if (hash.find(num) != hash.end())
                s.insert(num);
        }
        first = false;
    }
    for (int num : s)
        ans += to_string(num) + " ";
    if (!ans.empty())
        ans.pop_back();
    out << ans;
}


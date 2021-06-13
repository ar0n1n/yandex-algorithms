#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    unordered_map<string, int> hash;
    int n, k, num;
    int arr[1500];

    in >> n;
    for (int i = 1; i <= n; ++i)
        in >> arr[i];
    in >> k;
    for (int i = 0; i < k; ++i) {
        in >> num;
        --arr[num];
    }
    for (int i = 1; i <= n; ++i)
        out << (arr[i] < 0 ? "YES" : "NO") << endl;
}
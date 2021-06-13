#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    unordered_map<int, int> hash;
    int n, width, height;
    size_t ans(0);

    in >> n;
    for (int i = 0; i < n; ++i) {
        in >> width >> height;
        if (hash[width] < height) {
            ans += height - hash[width];
            hash[width] = height;
        }
    }
    out << ans;
}

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    size_t n, dist, ans = 0;
    ifstream in("input.txt");
    ofstream out("output.txt");
    in >> n >> dist;

    int arr[n];
    for (int i = 0; i < n; ++i)
        in >> arr[i];

    for (int l = 0, r = 1; r < n; ) {
        if (arr[r] - arr[l] > dist) {
            ans += n - r; ++l;
        }
        else ++r;
    }

    out << ans;
}
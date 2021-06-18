#include <iostream>
#include <limits.h>
#include <unordered_map>
using namespace std;

int main() {
    int n, k, l, len, unique, minlen, mnl, mnr;
    unordered_map<int,int> counter;

    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    mnl = mnr = l = len = unique = 0;
    minlen = INT_MAX;
    for (int r = 0; r < n; ++r) {
        counter[arr[r]]++; len++;
        if (counter[arr[r]] == 1)
            unique++;
        else {
            while (l < r && counter[arr[l]] > 1) {
                counter[arr[l]]--; len--; l++;
            }
        }
        if (unique == k && len < minlen) {
            minlen = len; mnl = l + 1; mnr = r + 1;
        }
    }

    printf("%d %d", mnl, mnr);
}

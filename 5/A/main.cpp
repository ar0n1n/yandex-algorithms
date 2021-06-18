#include <iostream>
using namespace std;

int main() {
    int n, m;

    scanf("%d", &n);
    int shirts[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &shirts[i]);

    scanf("%d", &m);
    int trousers[m];
    for (int i = 0; i < m; ++i)
        scanf("%d", &trousers[i]);

    int i = 0, j = 0, mindiff = abs(shirts[0] - trousers[0]),
            imin = 0, jmin = 0;
    while (i < n && j < m) {
        if (shirts[i] == trousers[j]) {
            imin = i; jmin = j; break;
        }
        if (abs(shirts[i] - trousers[j]) < mindiff) {
            imin = i; jmin = j;
            mindiff = abs(shirts[i] - trousers[j]);
        }
        if (shirts[i] < trousers[j]) ++i;
        else ++j;
    }

    printf("%d %d", shirts[imin], trousers[jmin]);
}
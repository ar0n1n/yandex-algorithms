#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool bsearch(vector<int> &arr, int val) {
    int64_t l = 0, r = arr.size() - 1, m;
    while (l <= r) {
        m = (l + r) / 2;
        if (arr[m] < val) l = m + 1;
        else if (arr[m] > val) r = m - 1;
        else return true;
    }
    return false;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    vector<int> arr1(n), arr2(k);
    for (int i = 0; i < n; ++i)
        cin >> arr1[i];
    for (int i = 0; i < k; ++i)
        cin >> arr2[i];
    sort(arr1.begin(), arr1.end());

    for (int i = 0; i < k; ++i) {
        if (bsearch(arr1, arr2[i]))
            printf("%s\n", "YES");
        else
            printf("%s\n", "NO");
    }
}


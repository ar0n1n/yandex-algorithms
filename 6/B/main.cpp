#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int64_t getClosest(int64_t a, int64_t b, int64_t val) {
    if (val - a <= b - val)
        return a;
    return b;
}

int64_t findClosest(vector<int64_t> &arr, int64_t val) {
    if (arr[0] > val) return arr[0];
    else if (arr.back() < val) return arr.back();

    int l = 0, r = arr.size(), m;
    while (l < r) {
        m = (l + r) / 2;
        if (arr[m] < val) {
            if (m < arr.size() - 1 && arr[m + 1] > val)
                return getClosest(arr[m], arr[m + 1], val);
            l = m + 1;
        }
        else if (arr[m] > val) {
            if (m > 0 && arr[m - 1] < val)
                return getClosest(arr[m - 1], arr[m], val);
            r = m;
        }
        else return arr[m];
    }
    return arr[m];
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    vector<int64_t> arr1(n), arr2(k);
    for (int i = 0; i < n; ++i)
        cin >> arr1[i];
    for (int i = 0; i < k; ++i)
        cin >> arr2[i];
    sort(arr1.begin(), arr1.end());

    for (int i = 0; i < k; ++i) {
        printf("%d\n", findClosest(arr1, arr2[i]));
    }
}
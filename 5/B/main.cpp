#include <iostream>
using namespace std;

int main() {
    size_t n, k, l = 0, sum = 0, ans = 0;
    cin >> n >> k;

    size_t nums[n];
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    for (int r = 0; r < n; ++r) {
        sum += nums[r];
        while (sum > k && l <= r)
            sum -= nums[l++];
        if (sum == k) {
            ++ans; sum -= nums[l++];
        }
    }

    cout << ans;
}
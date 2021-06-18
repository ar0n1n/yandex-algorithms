#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    scanf("%d", &n);

    vector<int> requests(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &requests[i]);
    sort(requests.begin(), requests.end());

    scanf("%d", &m);
    vector<pair<int,int>> offers;
    offers.reserve(m);
    for (int i = 0; i < m; ++i) {
        int power, price;
        scanf("%d %d", &power, &price);
        offers.push_back(make_pair(price, power));
    }
    sort(offers.begin(), offers.end());

    int i = 0, j = 0, ans = 0;
    while (i < n) {
        if (requests[i] <= offers[j].second) {
            ans += offers[j].first; i++;
        }
        else j++;
    }

    printf("%d", ans);
}
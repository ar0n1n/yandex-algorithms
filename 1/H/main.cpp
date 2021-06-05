#include <iostream>
using namespace std;

int main() {
	int a, b, n, m;
	int min1, max1, min2, max2;

	cin >> a >> b >> n >> m;

	min1 = (a + 1) * (n - 1) + 1;
	max1 = (a + 1) * (n + 1) - 1;
	min2 = (b + 1) * (m - 1) + 1;
	max2 = (b + 1) * (m + 1) - 1;

	if (max1 < min2 || max2 < min1)
		cout << -1 << endl;
	else
		cout << max(min1, min2) << ' ' << min(max1, max2) << endl;
}
#include <iostream>
using namespace std;


int main() {
	int n, k, m;

	cin >> n >> k >> m;

	if (n < k || k < m) {
		cout << 0 << endl;
		return 0;
	}

	int semi(0), finished(0);

	while (n >= k) {
		semi = n / k;
		finished += semi * (k / m);
		n = n % k + semi * (k % m);
	}

	cout << finished << endl;
}
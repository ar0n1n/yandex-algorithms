#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

int main() {
	int n, winner(INT_MIN), winner_id;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		if (winner < v[i]) {
			winner = v[i];
			winner_id = i;
		}
	}

	int vas(INT_MIN), place(1);

	for (int i = winner_id + 1; i < n; ++i) {
		if (v[i] % 10 != 5) continue;
		else if (i == n - 1 || v[i + 1] >= v[i]) continue;
		vas = max(vas, v[i]);
	}

	if (vas == INT_MIN)
		cout << 0 << endl;
	else {
		for (int i = 0; i < n; ++i)
			if (v[i] > vas) ++place;
		cout << place << endl;
	}
}
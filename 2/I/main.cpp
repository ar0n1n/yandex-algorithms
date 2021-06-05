#include <iostream>
using namespace std;

int main() {
	int n, m, k;

	cin >> n >> m >> k;

	int field[200][200];
	int n0, m0;
	for (int i = 0; i < k; ++i) {
		cin >> n0 >> m0;
		field[n0][m0] = 10;
		++field[n0-1][m0-1];
		++field[n0-1][m0];
		++field[n0][m0-1];
		++field[n0-1][m0+1];
		++field[n0][m0+1];
		++field[n0+1][m0+1];
		++field[n0+1][m0];
		++field[n0+1][m0-1];
	}

	string ans;

	ans.reserve(n * m * 3);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (field[i][j] >= 10)
				ans.append("*");
			else {
				ans.append(1, '0' + field[i][j]);
			}
			if (j < m)
				ans.append(1, ' ');
		}
		ans.append(1, '\n');
	}

	cout << ans;
}
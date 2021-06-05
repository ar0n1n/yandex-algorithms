#include <iostream>
#include <vector>
using namespace std;

int main() {
	int num, ans(0);
	vector<int> v;

	while (cin >> num)
		v.push_back(num);

	int n = v.size() - 1;
	for (size_t i = 1; i < n; ++i) {
		bool greaterThanNeighbours(true);
		if (v[i] <= v[i - 1])
			greaterThanNeighbours = false;
		else if (v[i] <= v[i + 1])
			greaterThanNeighbours = false;
		if (greaterThanNeighbours)
			++ans;
	}

	cout << ans << endl;
}
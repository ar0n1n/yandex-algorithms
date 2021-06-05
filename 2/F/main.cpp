#include <iostream>
#include <vector>
using namespace std;

bool isSymmetric(vector<int> &v, int start, int end) {
	int h = start + (v.size() - start) / 2;
	for ( ; start < h; ++start, --end) {
		if (v[start] != v[end])
			return false;
	}
	return true;
}

int main() {
	int n;
	vector<int> v;

	cin >> n;
	v.resize(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int i = 0;
	for ( ; i < n; ++i) {
		if (isSymmetric(v, i, v.size() - 1))
			break;
	}

	cout << i << endl;
	for (int j = i - 1; j >= 0; --j) {
		cout << v[j] << (j != 0 ? " " : "");
	}
}
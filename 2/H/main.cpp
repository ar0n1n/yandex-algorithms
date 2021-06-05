#include <iostream>
#include <vector>
using namespace std;

int main() {
	int num, max1, max2, max3, min1, min2;
	vector<int> v;

	while (cin >> num)
		v.push_back(num);

	if (v[0] >= v[1] && v[0] >= v[2]) {
		max1 = v[0];
		max2 = min2 = max(v[1], v[2]);
		max3 = min1 = min(v[1], v[2]);
	}
	else if (v[1] >= v[0] && v[1] >= v[2]) {
		max1 = v[1];
		max2 = min2 = max(v[0], v[2]);
		max3 = min1 = min(v[0], v[2]);
	}
	else {
		max1 = v[2];
		max2 = min2 = max(v[0], v[1]);
		max3 = min1 = min(v[0], v[1]);
	}

	for (size_t i = 3; i < v.size(); ++i) {
		if (v[i] > max1) {
			max3 = max2;
			max2 = max1;
			max1 = v[i];
		}
		else if (v[i] > max2) {
			max3 = max2;
			max2 = v[i];
		}
		else if (v[i] > max3)
			max3 = v[i];
		if (v[i] < min1) {
			min2 = min1;
			min1 = v[i];
		}
		else if (v[i] < min2)
			min2 = v[i];
	}
	if (max1 < 0)
		cout << max1 << ' ' << max2 << ' ' << max3 << endl;
	else if (max3 < 0)
		cout << min1 << ' ' << min2 << ' ' << max1 << endl;
	else {
		size_t pos = (size_t)max1 * (size_t)max2 * (size_t)max3;
		size_t neg = (size_t)abs(min1) * (size_t)abs(min2) * (size_t)max1;
		if (pos > neg)
			cout << max3 << ' ' << max2 << ' ' << max1 << endl;
		else
			cout << min1 << ' ' << min2 << ' ' << max1 << endl;
	}
}
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	double cur, prev, min(30), max(4000), median;
	string est;

	cin >> n >> prev;
	for (int i = 1; i < n; ++i) {
		cin >> cur >> est;
		median = (prev + cur) / 2;
		if (!est.compare("closer")) {
			if (cur < prev) max = std::min(max, median);
			else if (cur > prev) min = std::max(min, median);
		}
		else {
			if (cur < prev) min = std::max(min, median);
			else if (cur > prev) max = std::min(max, median);
		}
		prev = cur;
	}
	printf("%.6f %.6f", min, max);
}
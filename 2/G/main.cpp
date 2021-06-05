#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
	int num, max1, max2, min1, min2;
	vector<int> v;
	ifstream in("input.txt");
	ofstream out("output.txt");

	while (in >> num)
		v.push_back(num);

	max1 = min2 = max(v[0], v[1]);
	max2 = min1 = min(v[0], v[1]);
	for (size_t i = 2; i < v.size(); ++i) {
		if (v[i] >= 0) {
			if (v[i] > max1) {
				max2 = max1;
				max1 = v[i];
			}
			else if (v[i] > max2)
				max2 = v[i];
		}
		else {
			if (v[i] < min1) {
				min2 = min1;
				min1 = v[i];
			}
			else if (v[i] < min2)
				min2 = v[i];
		}
	}
	size_t pos = (size_t)max1 * (size_t)max2;
	size_t neg = (size_t)abs(min1) * (size_t)abs(min2);
	if (pos > neg)
		out << max2 << ' ' << max1 << endl;
	else
		out << min1 << ' ' << min2 << endl;
}
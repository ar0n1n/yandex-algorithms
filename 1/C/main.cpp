#include <iostream>
using namespace std;

void parseNumber(string &number) {
	getline(cin, number);

	string parsed;
	parsed.reserve(number.size());

	for (char c : number) {
		if (isdigit(c))
			parsed.push_back(c);
	}

	if (parsed.length() == 11)
		parsed.erase(parsed.begin());
	else if (parsed.length() == 7)
		parsed = "495" + parsed;

	number.swap(parsed);
}

int main() {
	string nnum;
	string nums[3];

	parseNumber(nnum);

	for (int i = 0; i < 3; ++i)
		parseNumber(nums[i]);

	for (int i = 0; i < 3; ++i) {
		if (!nnum.compare(nums[i]))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

}
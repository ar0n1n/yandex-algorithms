#include <iostream>
using namespace std;

int main() {
	string str, prev;
	bool isAsc(true);

	while (cin >> str) {
		if (!prev.empty() && str <= prev)
			isAsc = false;
		prev = str;
	}

	cout << (isAsc ? "YES" : "NO") << endl;
}
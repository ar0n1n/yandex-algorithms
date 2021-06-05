#include <iostream>
using namespace std;


int main() {
	int a, b, c;

	cin >> a >> b >> c;

	if (c < 0)
		cout << "NO SOLUTION" << endl;
	else if (a == 0) {
		if (c * c == b)
			cout << "MANY SOLUTIONS" << endl;
		else
			cout << "NO SOLUTION" << endl;
	}
	else {
		int numerator = c * c - b;
		if (numerator % a == 0)
			cout << numerator / a << endl;
		else
			cout << "NO SOLUTION" << endl;
	}
}
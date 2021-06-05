#include <iostream>
using namespace std;

int main() {
	int a, b, c, d, e;

	cin >> a >> b >> c >> d >> e;

	if ((a <= d && b <= e) || (a <= e && b <= d)
		|| (a <= d && c <= e) || (a <= e && c <= d)
		|| (b <= d && c <= e) || (b <= e && c <= d))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
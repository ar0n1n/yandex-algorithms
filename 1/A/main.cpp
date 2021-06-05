#include <iostream>
using namespace std;

int main() {
	int tRoom, tCond;
	string mode;

	cin >> tRoom >> tCond >> mode;

	if (!mode.compare("freeze"))
		cout << min(tRoom, tCond) << endl;
	else if (!mode.compare("heat"))
		cout << max(tRoom, tCond) << endl;
	else if (!mode.compare("auto"))
		cout << tCond << endl;
	else if (!mode.compare("fan"))
		cout << tRoom << endl;
	else
		cout << "Incorrect input" << endl;
}
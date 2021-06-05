#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int num, prev, type(-1);
	string types[] = {"CONSTANT", "ASCENDING", "WEAKLY ASCENDING",
					  "DESCENDING", "WEAKLY DESCENDING", "RANDOM"};

	scanf("%d", &prev);
	if (prev == -2000000000) {
		printf("%s", types[0].c_str());
		return 0;
	}

	while (true) {
		scanf("%d", &num);
		if (num == -2000000000)
			break;
		if (type == -1) {
			if (num > prev) type = 1;
			else if (num < prev) type = 3;
			else type = 0;
		}
		else {
			if (num == prev) {
				if (type == 1 || type == 3)
					++type;
			}
			else if (num > prev) {
				if (type == 0) type = 2;
				else if (type > 2) type = 5;
			}
			else {
				if (type == 0) type = 4;
				else if (type < 3) type = 5;
			}
		}
		prev = num;
	}

	printf("%s", types[type == -1 ? 0 : type].c_str());
}
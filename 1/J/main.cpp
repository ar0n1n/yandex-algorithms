#include <iostream>
#include <cmath>

using namespace std;

int main() {
	float a, b, c, d, e, f;

	cin >> a >> b >> c >> d >> e >> f;

	float zero = 1.0e-7;
	float D = a * d - c * b;
	float Dx = e * d - f * b;
	float Dy = a * f - c * e;
	if (not fabs(D) <= zero) {
		float x = Dx / D;
		float y = Dy / D;
		cout << 2 << " " << x << " " << y;
	}
	else {
		if (fabs(a) + fabs(b) + fabs(c) + fabs(d) <= zero) {
			if (fabs(e) + fabs(f) <= zero) cout << 5;
			else cout << 0;
		}
		else if ((not fabs(Dx) <= zero) || (not fabs(Dy) <= zero)) cout << 0; // нет решений
		else if (b == 0) {
			if (not fabs(a) <= zero) cout << 3 << " " << e / a;
			else if (fabs(d) <= zero) cout << 3 << " " << f / c;
			else if (fabs(c) <= zero) cout << 4 << " " << f / d;
			else cout << 1 << " " << -c/d << " " << f/d;
		}
		else if (a == 0) {
			if (not fabs(b) <= zero) cout << 4 << " " << e / b;
			else if (fabs(d) <= zero) cout << 3 << " " << f / c;
			else if (fabs(c) <= zero) cout << 4 << " " << f / d;
			else cout << 1 << " " << -c/d << " " << f/d;
		}
		else cout << 1 << " " << -a/b << " " << e/b;
	}
	return 0;
}
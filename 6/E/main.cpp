#include <iostream>

using namespace std;

int main() {
    uint64_t a, b, c, count, grades;
    cin >> a >> b >> c;

    count = a + b + c;
    grades = a * 2 + b * 3 + c * 4;
    uint64_t l = 0, r = count, m, wa;
    while (l < r) {
        m = (l + r) / 2;
        if ((grades + m * 5) * 2 >= (count + m) * 7)
            r = m;
        else l = m + 1;
    }

    cout << l;
}
#include <iostream>
using namespace std;

int main() {
    int a1, b1, a2, b2;

    cin >> a1 >> b1 >> a2 >> b2;

    int s1 = (a1 + a2) * max(b1, b2);
    int s2 = (a1 + b2) * max(b1, a2);
    int s3 = (b1 + b2) * max(a1, a2);
    int s4 = (b1 + a2) * max(a1, b2);

    int s_min = min(min(s1,s2),min(s3,s4));

    if (s_min == s1)
        cout << a1 + a2 << ' ' << max(b1, b2) << endl;
    else if (s_min == s2)
        cout << a1 + b2 << ' ' << max(b1, a2) << endl;
    else if (s_min == s3)
        cout << b1 + b2 << ' ' << max(a1, a2) << endl;
    else if (s_min == s4)
        cout << b1 + a2 << ' ' << max(a1, b2) << endl;
}
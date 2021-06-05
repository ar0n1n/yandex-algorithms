#include <iostream>
using namespace std;

int main() {
    int n, k1, p1(-1), n1(-1), k2, p2, n2;
    int p1_temp(-1), n1_temp(-1);
    bool p1_undef(false), n1_undef(false);

    cin >> k1 >> n >> k2 >> p2 >> n2;

    if (k2 < (n * (p2 - 1) + n2) || n2 > n)
        p1 = n1 = -1;
    else if (k2 == 1) {
        p1 = (k1 < n);
        n1 = (n == 1);
    }
    else if (n2 == 1 && p2 == 1) {
        n1 = (k1 < k2);
        p1 = (k1 < n * k2);
    }
    else {
        for (int rpb = 1; rpb < 1000; ++rpb) {
            if (rpb * (n * (p2 - 1) + n2 - 1) < k2
                && k2 <= rpb * (n * (p2 - 1) + n2)) {
                p1 = 1 + (k1 - 1) / (n * rpb);
                n1 = 1 + ((k1 - 1) % (n * rpb)) / rpb;

                if (p1_temp == -1) p1_temp = p1;
                else if (p1_temp != p1) p1_undef = true;

                if (n1_temp == -1) n1_temp = n1;
                else if (n1_temp != n1) n1_undef = true;
            }
        }
    }

    cout << (p1_undef? 0 : p1) << ' ' << (n1_undef ? 0 : n1) << endl;
}
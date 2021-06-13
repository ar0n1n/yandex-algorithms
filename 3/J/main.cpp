/// 1
#include <iostream>
#include <vector>
#include <list>
#include <fstream>

using namespace std;

void populateList(list<pair<int,int>> &v, int x, int y, int d) {
    for (int xadd = -d; xadd <= d; ++xadd) {
        int yadd_max = d - abs(xadd);
        v.push_back(make_pair(x + xadd, y));
        for (int yadd = 1; yadd <= yadd_max; ++yadd) {
            v.push_back(make_pair(x + xadd, y - yadd));
            v.push_back(make_pair(x + xadd, y + yadd));
        }
    }
}


int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int t, d, n, x, y, tn, err;
    in >> t >> d >> n;

    list<pair<int,int>> ans;
    vector<pair<int,int>> coords;

    coords.push_back(make_pair(0,0));
    for (int i = 0; i < n; ++i) {
        in >> x >> y;
        coords.push_back(make_pair(x, y));
    }
    populateList(ans, coords.back().first, coords.back().second, d);

    for (int i = coords.size() - 2; i >= 0; --i) {
        for (auto it = ans.begin(); it != ans.end(); ) {
            if ((abs(it->first - coords[i].first)
                 + abs(it->second - coords[i].second))
                > t * (n - i) + (i == 0 ? 0 : d)) {
                it = ans.erase(it);
            }
            else ++it;
        }
    }

    out << ans.size() << endl;
    for (auto p : ans) {
        out << p.first << ' ' << p.second << endl;
    }
}


/// 2
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n, t, d;
    in >> t >> d >> n;
    vector<int> x(n + 1), y(n + 1);
    x[0] = y[0] = 0;
    for (int i = 1; i <= n; ++i)
        in >> x[i] >> y[i];

    int cx = x[n], cy = y[n];
    vector<pair<int,int>> ans;
    for (int x0 = cx - d; x0 <= cx + d; ++x0) {
        for (int y0 = cy - d; y0 <= cy + d; ++y0) {
            bool isCorrectSolution = true;
            for (int i = 0; i <= n; ++i) {
                if (abs(x[i] - x0) + abs(y[i] - y0) > (n - i) * t + (i != 0 ? d : 0)) {
                    isCorrectSolution = false; break;
                }
            }
            if (isCorrectSolution) ans.push_back(make_pair(x0, y0));
        }
    }

    out << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
        out << ans[i].first << ' ' << ans[i].second << endl;

    return 0;
}


/// 3

#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n, t, d, x, y;
    in >> t >> d >> n;

    int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    for (int i = 0; i < n; ++i) {
        in >> x >> y;
        x1 -= t, y1 -= t, x2 += t, y2 += t;
        x1 = max(x1, x + y - d), y1 = max(y1, x - y - d);
        x2 = min(x2, x + y + d), y2 = min(y2, x - y + d);
    }
    vector<pair<int,int>> ans;
    for (int x = x1; x <= x2; ++x) {
        for (int y = y1; y <= y2; ++y)
            if ((x + y) % 2 == 0)
                ans.push_back(make_pair((x + y) / 2, (x - y) / 2));
    }
    out << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
        out << ans[i].first << ' ' << ans[i].second << endl;

    return 0;
}
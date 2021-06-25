///// V1 /////

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
    int64_t x, y;
};

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n, ans = 0;
    in >> n;

    vector<point> v;
    vector<vector<pair<int64_t,int64_t>>> dist(n);

    for (int i = 0; i < n; ++i) {
        point p; in >> p.x >> p.y;
        v.push_back(p);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            int64_t xdiff = (v[i].x - v[j].x);
            int64_t ydiff = (v[i].y - v[j].y);
            int64_t d =  xdiff * xdiff + ydiff * ydiff;
            dist[i].push_back(make_pair(d, j));
        }
    }

    for (int i = 0; i < n; ++i) {
        sort(dist[i].begin(), dist[i].end());
        int count = 0;
        for (int j = 0; j < dist[i].size(); ++j) {
            ++count;
            if (dist[i][j].first != dist[i][j + 1].first
                    || j == dist[i].size() - 1) {
                if (count > 1) {
                    for (int k = j - count + 1; k <= j; ++k) {
                        for (int m = k + 1; m <= j; ++m) {
                            if ((v[i].x * (v[dist[i][m].second].y - v[dist[i][k].second].y) +
                                 v[dist[i][m].second].x * (v[dist[i][k].second].y - v[i].y) +
                                 v[dist[i][k].second].x * (v[i].y - v[dist[i][m].second].y)) != 0)
                                ans += 1;
                        }
                    }
                }
                count = 0;
            }
        }
    }

    out << ans << endl;

    return 0;
}

///// V2 /////

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

struct point {
    int64_t x, y;
};

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n, ans = 0;
    in >> n;

    vector<point> v;
    vector<unordered_map<int64_t,vector<int>>> hash1(n);
    vector<vector<int64_t>> hash2(n, vector<int64_t>(n));

    for (int i = 0; i < n; ++i) {
        point p; in >> p.x >> p.y;
        v.push_back(p);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            int64_t xdiff = (v[i].x - v[j].x);
            int64_t ydiff = (v[i].y - v[j].y);
            int64_t dist =  xdiff * xdiff + ydiff * ydiff;
            hash1[i][dist].push_back(j);
            hash2[i][j] = dist;
        }
    }

//    for (int i = 0; i < n; ++i) {
//        for (auto &[dist, p] : hash1[i]) {
//            if (p.size() < 2) continue;
//            for (int j = 0; j < p.size(); ++j) {
//                for (int k = j + 1; k < p.size(); ++k) {
//                    if ((v[i].x * (v[p[j]].y - v[p[k]].y) + v[p[j]].x * (v[p[k]].y - v[i].y) +
//                        v[p[k]].x * (v[i].y - v[p[j]].y)) != 0)
//                        ans += 1;
//                }
//            }
//        }
//    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            int64_t dist = hash2[i][j];
            for (int k : hash1[i][dist]) {
                if (k == j) continue;
                if ((v[i].x * (v[j].y - v[k].y) +
                     v[j].x * (v[k].y - v[i].y) +
                     v[k].x * (v[i].y - v[j].y)) != 0)
                    ans += 1;
            }
        }
    }

    out << ans / 2 << endl;

    return 0;
}

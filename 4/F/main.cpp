#include <iostream>
#include <fstream>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    unordered_map<string, unordered_map<string, size_t>> hash;
    map<string, map<string, size_t>> sorted;
    string name, product;
    size_t quantity;

    while (in >> name >> product >> quantity)
        hash[name][product] += quantity;

    for (auto elem : hash) {
        map<string, size_t> m(elem.second.begin(), elem.second.end());
        sorted[elem.first] = m;
    }

    for (auto elem : sorted) {
        out << elem.first << ':' << endl;
        for (auto product : elem.second) {
            out << product.first << ' ' << product.second << endl;
        }
    }
}
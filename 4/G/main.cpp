#include <iostream>
#include <fstream>
#include <map>
#include <unordered_map>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    unordered_map<string, long long int> hash;
    string operation, name, name2;
    int amount;

    while (in >> operation) {
        if (!operation.compare("DEPOSIT")) {
            in >> name >> amount;
            hash[name] += amount;
        }
        else if (!operation.compare("WITHDRAW")) {
            in >> name >> amount;
            hash[name] -= amount;
        }
        else if (!operation.compare("BALANCE")) {
            in >> name;
            if (hash.find(name) == hash.end())
                out << "ERROR" << endl;
            else out << hash[name] << endl;
        }
        else if (!operation.compare("TRANSFER")) {
            in >> name >> name2 >> amount;
            hash[name] -= amount; hash[name2] += amount;
        }
        else if (!operation.compare("INCOME")) {
            in >> amount;
            for (auto &client : hash) {
                if (client.second > 0) {
                    client.second *= (100 + amount);
                    client.second /= 100;
                }
            }
        }
    }
}

#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    unordered_map<string, int> hash;
    string word, ans;
    int max(0);

    while (in >> word) {
        ++hash[word];
        if (hash[word] > max) {
            max = hash[word];
            ans.swap(word);
        }
        else if (hash[word] == max
                 && word < ans)
            ans.swap(word);
    }
    out << ans;
}
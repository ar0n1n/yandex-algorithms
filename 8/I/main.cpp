#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

int countHeirs(unordered_map<string, vector<string>> &tree,
               map<string,int> &ans, const string &root) {
    int count = 0;
    for (const auto &child : tree[root]) {
        count += countHeirs(tree, ans, child) + 1;
    }
    ans[root] = count;
    return count;
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n; in >> n;;
    string child, parent, root;
    map<string,int> ans;
    unordered_map<string,string> pairs;
    unordered_map<string, vector<string>> tree;

    for (int i = 1; i < n; ++i) {
        in >> child >> parent;
        pairs[child] = parent;
        tree[parent].push_back(child);
        ans.insert(make_pair(child,0));
        ans.insert(make_pair(parent, 0));
    }

    for (const auto &[person, count] : ans) {
        if (!pairs.count(person)) {
            root = person; break;
        }
    }

    countHeirs(tree, ans, root);

    for (const auto &[person, count] : ans) {
        out << person << " " << count << endl;
    }
}

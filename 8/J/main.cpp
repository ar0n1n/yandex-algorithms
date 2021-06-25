////// V1 //////

#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

int getLevel(unordered_map<string, string> &tree, string person) {
    int lvl = 0;

    while (tree.count(person)) {
        lvl += 1; person = tree[person];
    }

    return lvl;
}

int main() {
    int n; cin >> n;;
    string child, parent;
    unordered_map<string, string> tree;
    set<string> ans;

    for (int i = 1; i < n; ++i) {
        cin >> child >> parent;
        ans.insert(child); ans.insert(parent);
        tree[child] = parent;
    }

    for (string person : ans) {
        int lvl = getLevel(tree, person);
        cout << person << " " << lvl << endl;
    }
}

////// V2 //////

#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

int getLevel(unordered_map<string, string> &tree, const string &person) {
    if (!tree.count(person)) return 0;
    else return 1 + getLevel(tree, tree[person]);
}

int main() {
    int n; cin >> n;;
    string child, parent;
    unordered_map<string, string> tree;
    set<string> ans;

    for (int i = 1; i < n; ++i) {
        cin >> child >> parent;
        ans.insert(child); ans.insert(parent);
        tree[child] = parent;
    }

    for (auto &person : ans) {
        int lvl = getLevel(tree, person);
        cout << person << " " << lvl << endl;
    }
}
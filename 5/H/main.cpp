#include <iostream>
using namespace std;

int main() {
    int n, k, l = 0, maxlen = 0, start = 0;
    int counter[26] = {0};
    string str;

    cin >> n >> k >> str;

    for (int r = 0; r < n; ++r) {
        counter[str[r]-'a']++;
        while (counter[str[r]-'a'] > k)
            counter[str[l++]-'a']--;
        if (r - l + 1 > maxlen) {
            maxlen = r - l + 1; start = l + 1;
        }
    }

    printf("%d %d", maxlen, start);
}
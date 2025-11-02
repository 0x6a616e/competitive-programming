#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<string> s(n);
    vector<bool> l(27);
    for (string &si : s) {
        cin >> si;
        l[si[0] - 'A'] = true;
    }
    bool ans = false;
    for (string &si : s) {
        ans = ans || all_of(si.begin(), si.end(), [&l](char c) { return l[c - 'A']; });
        if (ans) break;
    }
    cout << (ans ? "Y" : "N") << '\n';

    return 0;
}

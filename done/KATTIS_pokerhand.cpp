#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    array<string, 5> s;
    for (string &si : s) {
        cin >> si;
    }

    unordered_map<char, int> cont;
    int ans = 0;
    for (string &si : s) {
        ans = max(ans, ++cont[si[0]]);
    }

    cout << ans << '\n';

    return 0;
}

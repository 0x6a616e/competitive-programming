// https://codeforces.com/problemset/problem/408/B

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string n, m;
    cin >> n >> m;

    vector<int> cont1(27, 0);
    vector<int> cont2(27, 0);

    for (char &c : n) ++cont1[c - 'a'];
    for (char &c : m) ++cont2[c - 'a'];

    bool posible = true;
    int sol = 0;

    for (int i = 0; i < 27 && posible; ++i) {
        if (cont2[i] && !cont1[i]) posible = false;
        sol += min(cont1[i], cont2[i]);
    }

    if (posible)
        cout << sol << '\n';
    else
        cout << "-1\n";

    return 0;
}

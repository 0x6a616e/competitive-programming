#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    string s;
    cin >> s;

    bool posible = true;
    int odd = 0;
    vector<int> cont(27, 0);

    for (char c : s) ++cont[c - 'a'];

    for (int c : cont)
        if (c % 2 != 0) ++odd;

    if (odd > 1 || (odd && (t % 2 == 0))) posible = false;

    if (posible)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}

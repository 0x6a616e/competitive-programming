// https://codeforces.com/problemset/problem/722/B

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    int p[n];
    for (int i = 0; i < n; ++i) cin >> p[i];

    set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y'};
    bool posible = true;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);

        int cont = 0;
        for (char c : s) cont += vowels.count(c);
        if (cont != p[i]) posible = false;
    }

    if (posible) cout << "YES\n";
    if (!posible) cout << "NO\n";

    return 0;
}

// https://cses.fi/problemset/task/1141

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> k(n);
    for (int i = 0; i < n; ++i) cin >> k[i];

    int begin = 0;
    int sol = 0;
    map<int, int> posiciones;
    for (int i = 0; i < n; ++i) {
        if (posiciones.count(k[i]) && posiciones[k[i]] >= begin) {
            begin = posiciones[k[i]] + 1;
        }
        posiciones[k[i]] = i;
        sol = max(sol, i - begin + 1);
    }

    cout << sol << '\n';

    return 0;
}

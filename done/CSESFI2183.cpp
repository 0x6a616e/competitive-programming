// https://cses.fi/problemset/task/2183/

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    int x[n];
    for (int i = 0; i < n; ++i) cin >> x[i];
    sort(x, x + n);

    unsigned long long acum = 1;
    int i = 0;
    while (i < n && acum >= x[i]) acum += x[i++];

    cout << acum << '\n';

    return 0;
}

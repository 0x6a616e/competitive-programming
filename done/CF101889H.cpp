#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int a, b, c;
    cin >> a >> b >> c;
    int d, e, f;
    cin >> d >> e >> f;

    int sol = 0;
    sol += max(0, d - a);
    sol += max(0, e - b);
    sol += max(0, f - c);

    cout << sol << endl;

    return 0;
}

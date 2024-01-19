// https://codeforces.com/problemset/problem/1184/A1

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    long long r;
    cin >> r;

    long long y;
    for (long long x = 1; x * x + x + 1 <= r; ++x) {
        y = r - x * x - x - 1;
        if (x > y) break;
        if (y % (2 * x) == 0) {
            y /= 2 * x;
            cout << x << ' ' << y << endl;
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}

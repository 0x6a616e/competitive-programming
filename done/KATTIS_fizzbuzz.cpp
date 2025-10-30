#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int x, y, n;
    cin >> x >> y >> n;

    for (int i = 1; i <= n; ++i) {
        if (i % x == 0) {
            cout << "Fizz";
        }
        if (i % y == 0) {
            cout << "Buzz";
        }
        if (i % x && i % y) {
            cout << i;
        }
        cout << '\n';
    }

    return 0;
}

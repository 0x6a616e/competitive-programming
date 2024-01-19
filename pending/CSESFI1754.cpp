#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t, a, b, diff;
    bool sol;
    cin >> t;

    while (t--) {
        cin >> a >> b;
        if (b > a) swap(a, b);

        sol = false;
        if (!a && !b)
            sol = true;
        else if (a == b * 2)
            sol = true;
        else if (a == b && a % 3 == 0)
            sol = true;
        else {
            diff = b - a;
            diff *= -1;
            a -= 2 * diff;
            b -= diff;
            if (a == b && a >= 0 && a % 3 == 0) sol = true;
        }

        if (sol)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}

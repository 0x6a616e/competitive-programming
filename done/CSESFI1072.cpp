// https://cses.fi/problemset/task/1072

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    unsigned long long sol;
    for (int i = 1; i <= n; ++i) {
        if (i == 1) sol = 0;
        if (i == 2) sol = 6;
        if (i > 2) {
            sol = sol + (2 * i - 1) * (i - 1) - 2;
            int offset = 0;
            for (int j = 0; j < i - 1; ++j) {
                int izq = 0;
                if (j > 0) izq = 1;
                if (j > 1) izq = 2;
                offset += 2 * izq;

                int der = 0;
                if (i - 2 - j > 0) der = 1;
                if (i - 2 - j > 1) der = 2;
                offset += 2 * der;
            }
            sol += 1LL * (2 * i - 1) * (i - 1) * (i - 1) - offset - 2;
        }
        cout << sol << '\n';
    }

    return 0;
}

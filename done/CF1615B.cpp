#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int l, r;
        cin >> l >> r;

        int base = log2(l);
        base = (1 << base);
        int best = 0;
        int curr = base;
        int cont = 0;
        while (curr <= r) {
            if (curr >= l) ++cont;
            curr = (curr + 1) | base;
        }
        best = max(best, cont);
        base <<= 1;
        curr = base;
        cont = 0;
        while (curr <= r) {
            if (curr >= l) ++cont;
            curr = (curr + 1) | base;
        }
        best = max(best, cont);

        cout << r - l + 1 - best << '\n';
    }

    return 0;
}

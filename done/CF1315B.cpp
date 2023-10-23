#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int a, b, p;
        cin >> a >> b >> p;

        string s;
        cin >> s;

        int sol = (int)s.size() - 1;

        while (p >= a || p >= b) {
            if (s[sol - 1] == 'A' && p >= a) {
                p -= a;
                for (sol = sol - 1; sol >= 0 && s[sol] == 'A'; --sol)
                    ;
                ++sol;
            } else if (s[sol - 1] == 'B' && p >= b) {
                p -= b;
                for (sol = sol - 1; sol >= 0 && s[sol] == 'B'; --sol)
                    ;
                ++sol;
            } else {
                break;
            }
        }

        cout << sol + 1 << '\n';
    }

    return 0;
}

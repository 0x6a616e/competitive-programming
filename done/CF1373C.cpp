#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int curr = 0;
        long long sol = 0;
        int acum = 0;

        for (int i = 0; i < (int)s.size(); ++i) {
            char c = s[i];
            if (c == '+')
                ++acum;
            else
                --acum;

            if (curr + acum < 0) {
                sol += (i + 1);
                ++curr;
            }
        }
        if (curr + acum >= 0) sol += s.size();
        cout << sol << '\n';
    }

    return 0;
}

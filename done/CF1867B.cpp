#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int hechos, por_hacer;
        hechos = por_hacer = 0;

        for (int i = 0; i < n / 2; ++i) {
            if (s[i] != s[n - i - 1]) ++por_hacer;
            if (s[i] == s[n - i - 1]) ++hechos;
        }

        string sol(n + 1, '0');
        for (int i = 0; i <= hechos; ++i) sol[por_hacer + 2 * i] = '1';
        if (n % 2)
            for (int i = 0; i <= hechos; ++i) sol[por_hacer + 1 + 2 * i] = '1';

        cout << sol << '\n';
    }

    return 0;
}

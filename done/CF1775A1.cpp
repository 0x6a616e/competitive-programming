#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        string s, a, b, c;
        cin >> s;

        bool terminado = false;
        for (int i = 1; i < (int)s.size() - 1 && !terminado; ++i) {
            for (int j = i; j < (int)s.size() - 1 && !terminado; ++j) {
                a = s.substr(0, i);
                b = s.substr(i, j - i + 1);
                c = s.substr(j + 1);
                if ((b <= a && b <= c) || (a <= b && c <= b)) {
                    cout << a << ' ' << b << ' ' << c << '\n';
                    terminado = true;
                }
            }
        }
    }

    return 0;
}

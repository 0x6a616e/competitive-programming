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
        vector<int> s(n + 1, 0);
        vector<int> last_c(n + 1, -1);
        for (int i = 0; i < n; ++i) {
            int c;
            cin >> c;
            if (last_c[c] == -1) ++s[c];
            if (last_c[c] != -1)
                if ((i - last_c[c]) % 2) ++s[c];

            last_c[c] = i;
        }

        for (int i = 1; i <= n; ++i) cout << (i > 1 ? " " : "") << s[i];
        cout << '\n';
    }

    return 0;
}

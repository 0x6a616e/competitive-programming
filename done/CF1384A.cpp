#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    string orig = string(50, 'a');
    while (t--) {
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; ++i) cin >> a[i];

        string s[n + 1];
        for (int i = 0; i <= n; ++i) s[i] = orig;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n + 1; ++j) {
                ++s[j][a[i]];
                if (s[j][a[i]] > 'z') s[j][a[i]] = 'a';
            }
        }

        for (int i = 0; i < n + 1; ++i) {
            cout << s[i] << '\n';
        }
    }

    return 0;
}

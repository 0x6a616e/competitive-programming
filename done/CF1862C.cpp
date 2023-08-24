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
        long long fence[n];
        for (int i = 0; i < n; ++i) cin >> fence[i];
        bool igual = true;
        if (fence[0] != n) igual = false;
        long long diff;
        for (int i = 1; i < n; ++i) {
            diff = fence[0] - fence[i];
            if (igual && diff && fence[n - diff] == fence[n - diff - 1])
                igual = false;
            if (igual && !diff && fence[n - 1] <= i) igual = false;
        }
        if (igual)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}

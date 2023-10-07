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

        long long sol;

        vector<int> d(n);
        for (int i = 0; i < n; ++i) cin >> d[i];
        sort(d.rbegin(), d.rend());

        if (n < 3) sol = 0;
        if (n >= 3) {
            int curr = n * -1 + 2;
            sol = 1LL * curr * d[0];
            ++curr;

            for (int i = 1; i < n; ++i) {
                sol += 1LL * curr * d[i];
                curr += 2;
            }
        }

        cout << sol << '\n';
    }

    return 0;
}

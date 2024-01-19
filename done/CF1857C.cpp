// https://codeforces.com/contest/1857/problem/C

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

        vector<int> b(n * (n - 1) / 2);

        for (size_t i = 0; i < b.size(); ++i) cin >> b[i];

        sort(b.rbegin(), b.rend());

        cout << b[0] << ' ' << b[0];

        size_t indexA = 2;
        size_t indexB = 1;
        while (indexB < b.size()) {
            cout << ' ' << b[indexB];
            indexB += indexA++;
        }

        cout << '\n';
    }

    return 0;
}

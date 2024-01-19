// https://codeforces.com/contest/1862/problem/B

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
        long long b[n];
        for (int i = 0; i < n; ++i) cin >> b[i];
        vector<long long> a;
        a.reserve(n * 2);
        a.push_back(b[0]);
        for (int i = 1; i < n; ++i) {
            if (b[i] >= a.back())
                a.push_back(b[i]);
            else {
                a.push_back(b[i]);
                a.push_back(b[i]);
            }
        }
        cout << a.size() << '\n';
        for (int i = 0; i < (int)a.size(); ++i) cout << (i ? " " : "") << a[i];
        cout << '\n';
    }

    return 0;
}

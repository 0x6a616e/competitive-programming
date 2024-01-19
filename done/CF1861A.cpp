// https://codeforces.com/contest/1861/problem/A

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n = 100;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++)
        if (is_prime[i])
            for (int j = i * i; j <= n; j += i) is_prime[j] = false;

    int t;
    cin >> t;

    while (t--) {
        string number;
        cin >> number;
        bool found = false;
        for (int i = 0; i < (int)number.size() && !found; ++i) {
            for (int j = i + 1; j < (int)number.size(); ++j) {
                n = (number[i] - '0') * 10 + (number[j] - '0');
                if (is_prime[n]) {
                    cout << n << '\n';
                    found = true;
                    break;
                }
            }
        }
        if (!found) cout << -1 << '\n';
    }

    return 0;
}

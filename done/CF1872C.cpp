// https://codeforces.com/problemset/problem/1872/C

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n = 10000000;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    vector<int> primes;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i) is_prime[j] = false;
        }
    }

    int t;
    cin >> t;

    while (t--) {
        int l, r;
        cin >> l >> r;

        bool found = false;
        for (int &prime : primes) {
            if (prime > r) break;

            int base = floor(r / (double)prime);
            if (prime * base >= l && base != 1) {
                cout << base << " " << (prime * base - base) << '\n';
                found = true;
                break;
            }
        }

        if (!found) cout << "-1\n";
    }

    return 0;
}

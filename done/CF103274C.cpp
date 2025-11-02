#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int lim = 1e6;
    vector<int> prime(lim + 1, 1);
    prime[0] = prime[1] = 0;
    for (int i = 2; (double)i * i <= lim; ++i) {
        if (!prime[i]) continue;
        for (int j = i * 2; j <= lim; j += i) {
            prime[j] = 0;
        }
    }
    for (int i = 1; i <= lim; ++i) {
        prime[i] += prime[i - 1];
    }

    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        cout << prime[r] - prime[l - 1] << '\n';
    }

    return 0;
}

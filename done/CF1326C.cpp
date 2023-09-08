#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int k, n;
    cin >> n >> k;
    int p;
    int last_limit = -1;
    int modulo = 998244353;
    unsigned long long acum = 0;
    unsigned long long sol = 1;

    for (int i = 0; i < n; ++i) {
        cin >> p;
        if (p > n - k && last_limit != -1) {
            int mid = (i - last_limit);
            sol *= mid;
            sol %= modulo;
        }
        if (p > n - k) {
            acum += p;
            last_limit = i;
        }
    }

    cout << acum << " " << sol << endl;

    return 0;
}

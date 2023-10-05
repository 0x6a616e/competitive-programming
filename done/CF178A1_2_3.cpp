#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    int a[n];
    int jump = log2(n);
    jump = (1 << (jump));

    for (int i = 0; i < n; ++i) cin >> a[i];

    long long sol = 0;

    for (int i = 0; i < n - 1; ++i) {
        if (i + jump >= n) jump >>= 1;
        sol += a[i];
        a[i + jump] += a[i];
        cout << sol << '\n';
    }

    return 0;
}

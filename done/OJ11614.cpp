#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        unsigned long long n;
        cin >> n;
        long double res = -1.0 + sqrt(n * 8 + 1);
        res /= 2;
        cout << int(res) << '\n';
    }

    return 0;
}

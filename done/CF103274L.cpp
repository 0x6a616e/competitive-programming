#include <bits/stdc++.h>

using namespace std;

string solve(long long k) {
    if (k == 1) return "2";
    string ans = "";
    if (k % 2 == 0) {
        ans += "(";
        ans += solve(k >> 1);
        ans += ")^2";
    } else {
        ans += "(2*";
        ans += solve(k - 1);
        ans +=")";
    }
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        long long k;
        cin >> k;
        cout << solve(k) << '\n';
    }

    return 0;
}

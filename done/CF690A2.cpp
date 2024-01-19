// https://codeforces.com/problemset/problem/690/A2

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    if (n % 2 == 0) {
        int jump = log2(n);
        n -= (1 << jump);
    }
    cout << n / 2 << endl;

    return 0;
}

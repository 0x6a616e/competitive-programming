#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    int k;
    cin >> k;

    int sol = k / n;
    int rem = k % n;
    if (rem < (n - 1)) --sol;

    cout << sol << endl;

    return 0;
}

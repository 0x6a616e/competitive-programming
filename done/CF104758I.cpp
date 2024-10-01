#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    if (n % k == 0)
        cout << k << endl;
    else
        cout << (n % k) << endl;

    return 0;
}

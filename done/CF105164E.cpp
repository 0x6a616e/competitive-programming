#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int a, b, k;
    cin >> a >> b >> k;

    for (int x = 1; x <= k; ++x) {
        cout << (x == 1 ? "" : " ") << (a * x + b);
    }
    cout << endl;

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, acum;
    cin >> n;
    acum = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        acum += a;
    }

    int sol = 0;
    while (acum % n != 0) {
        ++sol;
        --n;
    }
    cout << sol << endl;

    return 0;
};

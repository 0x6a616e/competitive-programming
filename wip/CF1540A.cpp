#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int d;
        for (int i = 0; i < n; ++i) cin >> d;

        if (n == 1 || n == 2)
            cout << "0\n";
        else
            cout << '-' << d << '\n';
    }

    return 0;
}

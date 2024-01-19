// https://cses.fi/problemset/task/1070

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    if (n == 1)
        cout << "1\n";
    else if (n <= 3)
        cout << "NO SOLUTION\n";
    else {
        int l = 1;
        int r = n / 2 + 1;

        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0)
                cout << r++ << ' ';
            else
                cout << l++ << ' ';
        }
        cout << '\n';
    }

    return 0;
}

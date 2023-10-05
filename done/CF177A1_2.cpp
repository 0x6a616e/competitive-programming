#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    int a;
    int middle = n / 2;
    int sol = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a;
            if (i == j)
                sol += a;
            else if (i == middle)
                sol += a;
            else if (j == middle)
                sol += a;
            else if (i + j == n - 1)
                sol += a;
        }
    }

    cout << sol << '\n';

    return 0;
}

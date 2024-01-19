// https://codeforces.com/problemset/problem/1375/B

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        int mat[n][m];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) cin >> mat[i][j];

        bool posible = true;
        if (mat[0][0] > 2) posible = false;
        mat[0][0] = 2;

        if (mat[0][m - 1] > 2) posible = false;
        mat[0][m - 1] = 2;

        if (mat[n - 1][0] > 2) posible = false;
        mat[n - 1][0] = 2;

        if (mat[n - 1][m - 1] > 2) posible = false;
        mat[n - 1][m - 1] = 2;

        for (int i = 1; i < m - 1; ++i) {
            if (mat[0][i] > 3) posible = false;
            mat[0][i] = 3;

            if (mat[n - 1][i] > 3) posible = false;
            mat[n - 1][i] = 3;
        }

        for (int i = 1; i < n - 1; ++i) {
            if (mat[i][0] > 3) posible = false;
            mat[i][0] = 3;

            if (mat[i][m - 1] > 3) posible = false;
            mat[i][m - 1] = 3;
        }

        for (int i = 1; i < n - 1; ++i) {
            for (int j = 1; j < m - 1; ++j) {
                if (mat[i][j] > 4) posible = false;
                mat[i][j] = 4;
            }
        }

        if (posible) {
            cout << "YES\n";
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cout << (j ? " " : "") << mat[i][j];
                }
                cout << '\n';
            }
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

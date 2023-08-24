#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        string grid[n];
        for (int i = 0; i < n; ++i) cin >> grid[i];
        string target = "vika";
        int index = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[j][i] == target[index]) {
                    ++index;
                    break;
                }
        if (index == 4)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}

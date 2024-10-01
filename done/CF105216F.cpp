#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, p;
    cin >> n >> p;
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        if (v <= p) sol = max(sol, v);
    }

    cout << sol << endl;

    return 0;
}

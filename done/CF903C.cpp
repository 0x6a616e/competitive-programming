// https://codeforces.com/problemset/problem/903/C

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a, a + n, greater<int>());

    vector<int> sol;
    sol.reserve(n);

    for (int ai : a) {
        bool insertado = false;
        for (int i = 0; i < (int)sol.size() && !insertado; ++i) {
            if (ai < sol[i]) {
                sol[i] = ai;
                insertado = true;
            }
        }
        if (!insertado) sol.push_back(ai);
    }

    cout << sol.size() << endl;

    return 0;
}

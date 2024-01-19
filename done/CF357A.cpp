// https://codeforces.com/problemset/problem/357/A

#include <bits/stdc++.h>

using namespace std;

int main() {
    int m;
    int izq = 0;
    int der = 0;
    cin >> m;
    vector<int> c(m);
    for (int i = 0; i < m; ++i) {
        cin >> c[i];
        der += c[i];
    }
    int x, y;
    cin >> x >> y;
    int sol = 0;
    while (sol < m && (izq < x || izq > y || der < x || der > y)) {
        izq += c[sol];
        der -= c[sol];
        ++sol;
    }
    if (sol == m)
        cout << "0\n";
    else
        cout << sol + 1 << '\n';
    return 0;
}

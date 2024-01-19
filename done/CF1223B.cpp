// https://codeforces.com/problemset/problem/1223/B

#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        string s, t;
        cin >> s >> t;
        bool posible = false;
        for (int i = 0; i < (int)s.size(); ++i)
            if (t.find(s[i]) != -1) posible = true;
        if (posible)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}

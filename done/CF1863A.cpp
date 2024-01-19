// https://codeforces.com/contest/1863/problem/A

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a, q;
        cin >> n >> a >> q;
        int pendientes = n - a;
        int online = 0;

        char notif;
        bool g = (n == a);
        string notifs;
        cin >> notifs;
        for (int i = 0; i < q; ++i) {
            notif = notifs[i];
            if (notif == '-') {
                --a;
            } else {
                ++online;
                ++a;
            }
            if (a == n) g = true;
        }

        if (g)
            cout << "YES\n";
        else if (pendientes <= online)
            cout << "MAYBE\n";
        else
            cout << "NO\n";
    }
    return 0;
}

// https://codeforces.com/contest/1861/problem/B

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;

        int s = (int)s1.size();

        bool found = false;
        for (int i = 0; i < s - 1 && !found; ++i)
            if (s1[i] == '0' && s1[i + 1] == '1' && s2[i] == '0' &&
                s2[i + 1] == '1')
                found = true;

        if (found)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}

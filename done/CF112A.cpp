// https://codeforces.com/problemset/problem/112/A

#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        string a, b;

        cin >> a;
        cin >> b;

        for (int i = 0; i < a.size(); i++) {
                a[i] = tolower(a[i]);
        }

        for (int i = 0; i < b.size(); i++) {
                b[i] = tolower(b[i]);
        }

        if (a < b) {
                cout << "-1\n";
        } else if (a == b) {
                cout << "0\n";
        } else {
                cout << "1\n";
        }
        
        return 0;
}

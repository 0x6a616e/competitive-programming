// https://codeforces.com/problemset/problem/110/A

#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int c = 0;
        string n;

        cin >> n;

        for (int i = 0; i < n.size(); i++) {
                if (n[i] == '4' || n[i] == '7') {
                        c++;
                }
        }

        if (c == 4 || c == 7) {
                cout << "YES\n";
        } else {
                cout << "NO\n";
        }
        
        return 0;
}

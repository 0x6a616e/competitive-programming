// https://codeforces.com/problemset/problem/266/A

#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int n, c = 0, i = 0;
        string s;

        cin >> n;
        cin >> s;

        while (s.size() > 1 && i < s.size()) {
                if (s[i] == s[i + 1]) {
                        c++;
                        s = s.erase(i + 1, 1);
                } else {
                        i++;
                }
        }

        cout << c << '\n';
        
        return 0;
}

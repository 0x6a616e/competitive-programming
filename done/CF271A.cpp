// https://codeforces.com/problemset/problem/271/A

#include <bits/stdc++.h>

using namespace std;

bool distinct(string s) {
        set<char> chars;
        chars.insert(s[0]);
        chars.insert(s[1]);
        chars.insert(s[2]);
        chars.insert(s[3]);
        return chars.size() == 4;
}

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int y;
        
        cin >> y;

        for (int i = y + 1; i < 10000; i++) {
                if (distinct(to_string(i))) {
                        cout << i << endl;
                        break;
                }
        }
        
        return 0;
}

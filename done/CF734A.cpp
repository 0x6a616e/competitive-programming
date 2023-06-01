// https://codeforces.com/problemset/problem/734/A

#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int n;
        char w;
        unordered_map<char, int> contador;

        cin >> n;

        for (int i = 0; i < n; i++) {
                cin >> w;
                contador[w]++;
        }

        if (contador['A'] == contador['D']) {
                cout << "Friendship\n";
        } else if (contador['A'] > contador['D']) {
                cout << "Anton\n";
        } else {
                cout << "Danik\n";
        }
        
        return 0;
}

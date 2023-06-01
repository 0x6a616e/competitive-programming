// https://codeforces.com/problemset/problem/236/A

#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        char letra;
        set<char> letras;

        while (cin >> letra) {
                letras.insert(letra);
        }

        if (letras.size() % 2 == 0) {
                cout << "CHAT WITH HER!\n";
        } else {
                cout << "IGNORE HIM!\n";
        }
        
        return 0;
}

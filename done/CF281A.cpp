// https://codeforces.com/problemset/problem/281/A

#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        string palabra;
        cin >> palabra;

        cout << char(toupper(palabra[0])) + palabra.substr(1) << '\n';

        return 0;
}

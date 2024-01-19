// https://codeforces.com/problemset/problem/59/A

#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int mayus = 0;
        string palabra, palabraMayusc, palabraMinusc;

        cin >> palabra;

        palabraMayusc = palabraMinusc = palabra;

        for (int i = 0; i < palabra.size(); i++) {
                if (isupper(palabra[i])) {
                        mayus++;
                }
                palabraMayusc[i] = char(toupper(palabra[i]));
                palabraMinusc[i] = char(tolower(palabra[i]));
        }

        if (mayus > palabra.size() / 2) {
                cout << palabraMayusc << '\n';
        } else {
                cout << palabraMinusc << '\n';
        }
        
        return 0;
}

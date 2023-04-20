// Problema que vimos en el club
// Trata de obtener la string lexicograficamente más grande sin duplicados
// ABCB -> ACB
// ADADA -> DA

#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        string palabra, res;
        map<char, int> posiciones;

        cin >> palabra;
        res = palabra[palabra.size() - 1];
        posiciones[palabra[palabra.size() - 1]] = 1;

        for (int i = palabra.size() - 2; i >= 0; i--) {
                if (posiciones[palabra[i]]) {
                        if (palabra[i] > res[res.size() - 1]) {
                                res[posiciones[palabra[i]] - 1] = ' ';
                                res += palabra[i];
                                posiciones[palabra[i]] = res.size();
                        }
                } else {
                        res += palabra[i];
                        posiciones[palabra[i]] = res.size();
                }
        }

        for (int i = res.size() - 1; i >= 0; i--) {
                if (res[i] != ' ') {
                        cout << res[i];
                }
        }
        cout << '\n';
        
        return 0;
}

// https://codeforces.com/gym/104375/problem/A

#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int N, X, contador = 0;
        string nombre, NAME;
        map<string, int> encontrado;

        cin >> N;

        while (N--) {
                cin >> X;
                NAME = "";
                while (X--) {
                        cin >> nombre;
                        NAME += nombre[0];
                }
                if (encontrado[NAME] == 1) {
                        contador--;
                }
                if (!encontrado[NAME]++) {
                        contador++;
                }
        }

        cout << contador << '\n';

        return 0;
}

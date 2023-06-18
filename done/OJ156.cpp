#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        string palabra;
        vector<string> originales;
        map<string, int> conteo;

        while (cin >> palabra && palabra != "#") {
                originales.push_back(palabra);
                for (size_t i = 0; i < palabra.size(); i++) {
                        palabra[i] = tolower(palabra[i]);
                }
                sort(palabra.begin(), palabra.end());
                conteo[palabra]++;
        }

        sort(originales.begin(), originales.end());

        for (size_t i = 0; i < originales.size(); i++) {
                palabra = originales[i];
                for (size_t i = 0; i < palabra.size(); i++) {
                        palabra[i] = tolower(palabra[i]);
                }
                sort(palabra.begin(), palabra.end());
                if (conteo[palabra] == 1) {
                        cout << originales[i] << '\n';
                }
        }
        
        return 0;
}

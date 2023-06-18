#include <bits/stdc++.h>

using namespace std;

bool ordena(string &a, string &b) {
        for (size_t i = 0; i < a.size(); i++) {
                if (tolower(a[i]) == tolower(b[i])) {
                        if (isupper(a[i]) && !isupper(b[i])) {
                                return true;
                        } else if (isupper(b[i]) && !isupper(a[i])) {
                                return false;
                        }
                } else {
                        return tolower(a[i]) < tolower(b[i]);
                }
        }
}

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int t;

        cin >> t;

        while (t--) {
                string letras;
                cin >> letras;

                sort(letras.begin(), letras.end());

                vector<string> permutaciones;
                do {
                        permutaciones.push_back(letras);
                } while (next_permutation(letras.begin(), letras.end()));

                sort(permutaciones.begin(), permutaciones.end(), ordena);

                for (size_t i = 0; i < permutaciones.size(); i++) {
                        cout << permutaciones[i] << '\n';
                }
        }
        
        return 0;
}

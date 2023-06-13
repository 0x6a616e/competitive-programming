#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int round;

        while (cin >> round && round != -1) {
                int fallidos = 0;
                string palabra, intento;
                set<char> letras;

                cin >> palabra;
                cin >> intento;

                for (int i = 0; i < palabra.size(); i++) {
                        letras.insert(palabra[i]);
                }
                
                for (int i = 0; i < intento.size() && letras.size() > 0 && fallidos < 7; i++) {
                        if (letras.find(intento[i]) == letras.end()) {
                                fallidos++;
                        }
                        letras.erase(intento[i]);
                }

                cout << "Round " << round << '\n';
                if (letras.size() == 0) {
                        cout << "You win.\n";
                } else if (fallidos == 7) {
                        cout << "You lose.\n";
                } else {
                        cout << "You chickened out.\n";
                }
        }
        
        return 0;
}

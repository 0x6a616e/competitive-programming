#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int casos;

        cin >> casos;

        while (casos--) {
                int jugadores, n_portales, turnos, entrada, salida, tirada;
                map<int, int> portales;
                cin >> jugadores >> n_portales >> turnos;

                for (int i = 0; i < n_portales; i++) {
                        cin >> entrada >> salida;
                        portales[entrada] = salida;
                }

                int turno = 0;
                vector<int> posiciones(jugadores, 1);

                bool leyendo = true;

                for (int i = 0; i < turnos; i++) {
                        cin >> tirada;
                        if (leyendo) {
                                posiciones[turno] += tirada;
                                if (portales[posiciones[turno]]) {
                                        posiciones[turno] = portales[posiciones[turno]];
                                }
                                if (posiciones[turno] >= 100) {
                                        posiciones[turno] = 100;
                                        leyendo = false;
                                }
                                turno++;
                                turno %= jugadores;
                        }
                }

                for (int i = 0; i < jugadores; i++) {
                        cout << "Position of player " << (i + 1) << " is " << posiciones[i] << ".\n";
                }
        }
        
        return 0;
}

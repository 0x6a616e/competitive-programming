#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int cant_requerimientos, cant_ofertas, cant_requerimientos_oferta, mejor_requerimientos, mejor_precio, contador = 0;
        double precio;
        string basura, requerimiento, oferta, mejor_nombre;

        while (cin >> cant_requerimientos >> cant_ofertas && cant_requerimientos != 0 && cant_ofertas != 0) {
                getline(cin, basura);
                mejor_requerimientos = 0;
                for (int i = 0; i < cant_requerimientos; i++) {
                        getline(cin, requerimiento);
                }
                for (int i = 0; i < cant_ofertas; i++) {
                        getline(cin, oferta);
                        cin >> precio >> cant_requerimientos_oferta;
                        getline(cin, basura);
                        for (int j = 0; j < cant_requerimientos_oferta; j++) {
                                getline(cin, requerimiento);
                        }
                        if (mejor_requerimientos == 0) {
                                mejor_nombre = oferta;
                                mejor_precio = precio;
                                mejor_requerimientos = cant_requerimientos_oferta;
                        } else if (cant_requerimientos_oferta == mejor_requerimientos) {
                                if (precio < mejor_precio) {
                                        mejor_nombre = oferta;
                                        mejor_precio = precio;
                                        mejor_requerimientos = cant_requerimientos_oferta;
                                }
                        } else if (cant_requerimientos_oferta > mejor_requerimientos) {
                                mejor_nombre = oferta;
                                mejor_precio = precio;
                                mejor_requerimientos = cant_requerimientos_oferta;
                        }
                }
                if (contador) {
                        cout << '\n';
                }
                cout << "RFP #" << ++contador << '\n';
                cout << mejor_nombre << "\n";
        }

        return 0;
}

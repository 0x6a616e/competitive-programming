#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool validadorIntento(vector<int> &intento)
{
        return !all_of(intento.begin(), intento.end(), [](int &i) { return i == 0; });
}

int main()
{       
        int N, numero, fuertes, debiles, c = 0;
        vector<int> codigo, codigoAux, intento;
        vector<int>::iterator posicion;

        while (cin >> N && N != 0) {
                c++;
                cout << "Game " << c << ":\n";
                codigo.clear();
                for (int i = 0; i < N; i++) {
                        cin >> numero;
                        codigo.push_back(numero);
                }
                while (true) {
                        codigoAux = codigo;
                        intento.clear();
                        fuertes = 0;
                        debiles = 0;
                        for (int i = 0; i < N; i++) {
                                cin >> numero;
                                intento.push_back(numero);
                        }
                        if (!validadorIntento(intento)) {
                                break;
                        }
                        numero = N;
                        for (int i = 0; i < numero; i++) {
                                if (codigoAux[i] == intento[i]) {
                                        fuertes++;
                                        codigoAux.erase(codigoAux.begin() + i);
                                        intento.erase(intento.begin() + i);
                                        i--;
                                        numero--;
                                }
                        }
                        while (intento.size() != 0) {
                                posicion = find(codigoAux.begin(), codigoAux.end(), intento.back());
                                intento.pop_back();
                                if (posicion != codigoAux.end()) {
                                        debiles++;
                                        codigoAux.erase(posicion);
                                }
                        }
                        cout << "    (" << fuertes << "," << debiles << ")\n";
                }
        }
        
        return 0;
}
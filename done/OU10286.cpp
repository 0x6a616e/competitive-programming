#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

int main()
{
        cin.tie(NULL);
        ios_base::sync_with_stdio(false);

        int Q, distancia, digito;
        string N, intento;
        queue<string> intentos;
        pair<int, string> menor;

        cin >> Q;

        while (Q--) {
                cin >> N;

                menor = { 1000, "" };

                for (int i = 1; i < 10; i++)
                        intentos.push(to_string(i));

                while (!intentos.empty()) {
                        intento = intentos.front();
                        intentos.pop();

                        distancia = abs(stoi(N) - stoi(intento));
                        if (distancia == menor.first)
                                menor.second = min(menor.second, intento);
                        if (distancia < menor.first)
                                menor = { distancia, intento };

                        if (intento.length() < 4) {
                                digito = stoi(intento) % 10;
                                if (digito == 0 || digito % 3 != 0)
                                        intentos.push(intento + "0");
                                for (int i = digito; i != 0 && i < 10; i += 3)
                                        for (int j = 0; j < 3 - ((i - 1) % 3); j++)
                                                intentos.push(intento + to_string(i + j));
                        }
                }

                cout << menor.second << '\n';
        }
        
        return 0;
}

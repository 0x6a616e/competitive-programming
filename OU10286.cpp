#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

int main()
{
        cin.tie(NULL);
        ios_base::sync_with_stdio(false);

        int Q, distancia;
        string N, intento;
        queue<string> intentos;
        pair<int, string> menor;

        cin >> Q;

        while (Q--) {
                cin >> N;

                menor = { 10000, "" };

                intentos.push(N.substr(0, 1));

                while (!intentos.empty()) {
                        intento = intentos.front();
                        intentos.pop();

                        if (N.length() == intento.length()) {
                                distancia = abs(stoi(N) - stoi(intento));
                                if (distancia == menor.first)
                                        menor.second = min(menor.second, intento);
                                if (distancia < menor.first)
                                        menor = { distancia, intento };
                        } else {
                                intentos.push(intento + "0");
                                for (int i = stoi(intento) % 10; i != 0 && i < 10; i += 3)
                                        for (int j = 0; j < 3 - ((i - 1) % 3); j++)
                                                intentos.push(intento + to_string(i + j));
                        }
                }

                cout << menor.second << '\n';
        }
        
        return 0;
}

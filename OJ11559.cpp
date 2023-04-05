#include <bits/stdc++.h>

using namespace std;

int main() {
        cin.tie(0);
        ios::sync_with_stdio(0);

        int personas, presupuesto, cant_hoteles, num_semanas, menor, precio_individual, capacidad;
        bool posible;

        while (cin >> personas >> presupuesto >> cant_hoteles >> num_semanas) {
                menor = 500000;
                for (int i = 0; i < cant_hoteles; i++) {
                        posible = false;
                        cin >> precio_individual;
                        for (int j = 0; j < num_semanas; j++) {
                                cin >> capacidad;
                                if (capacidad >= personas) {
                                        posible = true;
                                }
                        }
                        if (posible) {
                                menor = min(menor, personas * precio_individual);
                        }
                }
                if (menor >= presupuesto) {
                        cout << "stay home\n";
                } else {
                        cout << menor << '\n';
                }
        }

        return 0;
}

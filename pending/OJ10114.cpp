#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int duracion, cant_devaluaciones, mes, res;
        double pago, deuda, devaluacion, valor_carro, cant_pago;
        vector<double> devaluaciones(101);

        while (cin >> duracion >> pago >> deuda >> cant_devaluaciones && duracion >= 0) {
                valor_carro = pago + deuda;
                cant_pago = deuda / duracion;
                for (int i = 0; i < cant_devaluaciones; i++) {
                        cin >> mes;
                        cin >> devaluacion;
                        for (int j = mes; j < 101; j++) {
                                devaluaciones[j] = devaluacion;
                        }
                }

                for (int i = 0; i <= duracion; i++) {
                        valor_carro -= valor_carro * devaluaciones[i];
                        if (deuda < valor_carro) {
                                res = i;
                                break;
                        }
                        deuda -= cant_pago;
                }

                if (res == 1) {
                        cout << "1 month\n";
                } else {
                        cout << res << " months\n";
                }
        }

        return 0;
}

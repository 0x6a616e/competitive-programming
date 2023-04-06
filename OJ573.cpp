#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int H, D, dias;
        double F, U, U_original, altura_actual;
        bool salio;

        while (cin >> H >> U >> D >> F && H != 0) {
                salio = false;
                F /= 100;
                dias = 0;
                altura_actual = 0;
                U_original = U;

                while (true) {
                        dias++;
                        altura_actual += U;
                        if (altura_actual > H) {
                                salio = true;
                                break;
                        }
                        altura_actual -= D;
                        if (altura_actual < 0) {
                                break;
                        }
                        U = max(0.0, U - U_original * F);
                }

                if (salio) {
                        cout << "success on day " << dias << '\n';
                } else {
                        cout << "failure on day " << dias << '\n';
                }
        }

        return 0;
}

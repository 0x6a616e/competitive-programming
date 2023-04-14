#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int casos, alumnos, velocidad, mayor;

        cin >> casos;

        for (int i = 0; i < casos; i++) {
                mayor = 0;
                cin >> alumnos;

                for (int j = 0; j < alumnos; j++) {
                        cin >> velocidad;
                        mayor = max(mayor, velocidad);
                }

                cout << "Case " << i + 1 << ": " << mayor << '\n';
        }
}

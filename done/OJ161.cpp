#include <bits/stdc++.h>

using namespace std;

void printTime(int seconds) {
        int hours = seconds / 3600;
        int minutes = (seconds % 3600) / 60;
        int secs = seconds % 60;
        
        cout << setfill('0') << setw(2) << hours << ":" << setfill('0') << setw(2) << minutes << ":" << setfill('0') << setw(2) << secs << '\n';
}

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int señal;
        vector<int> señales(3);

        while (cin >> señales[0] >> señales[1] >> señales[2]) {
                if (!señales[0] && !señales[1] && !señales[2]) {
                        break;
                }

                int minimo = min({ señales[0], señales[1] });

                if (señales[2]) {
                        minimo = min(minimo, señales[2]);
                }

                while (señales.back() != 0) {
                        cin >> señal;
                        if (señal) {
                                minimo = min(minimo, señal);
                        }
                        señales.push_back(señal);
                }

                señales.pop_back();

                int sol;
                bool esSol = false;

                for (sol = minimo * 2; sol <= 18000 && !esSol; sol++) {
                        esSol = true;
                        for (size_t i = 0; i < señales.size() && esSol; i++) {
                                if ((sol / señales[i]) % 2 || (sol % señales[i] >= (señales[i] - 5))) {
                                        esSol = false;
                                }
                        }
                }

                if (esSol) {
                        sol--;
                        printTime(sol);
                } else {
                        cout << "Signals fail to synchronise in 5 hours\n";
                }

                señales.resize(3);
        }
        
        return 0;
}

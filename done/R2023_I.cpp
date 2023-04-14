#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
        cin.tie(nullptr);
        ios_base::sync_with_stdio(false);

        short int R, C, mayor = 0, num;
        vector<short int> filaA;
        vector<set<short int>> adyacencias;
        set<short int>::iterator it;

        cin >> R >> C;

        filaA.resize(C);
        adyacencias.resize(R * C + 1);

        for (short int i = 0; i < R; i++) {
                for (short int j = 0; j < C; j++) {
                        cin >> num;
                        if (i > 0) {
                                if (num > filaA[j]) {
                                        adyacencias[filaA[j]].insert(num);
                                } else {
                                        adyacencias[num].insert(filaA[j]);
                                }
                        }
                        filaA[j] = num;
                        if (j > 0) {
                                if (filaA[j] > filaA[j - 1]) {
                                        adyacencias[filaA[j - 1]].insert(filaA[j]);
                                } else {
                                        adyacencias[filaA[j]].insert(filaA[j - 1]);
                                }
                        }
                }
        }

        filaA.clear();

        set<short int> visitados;

        for (short int i = 1; i <= R * C; i++) {
                if (visitados.find(i) != visitados.end()) {
                        continue;
                }
                for (it = adyacencias[i].begin(); it != adyacencias[i].end(); it++) {
                        visitados.insert(*it);
                        adyacencias[i].insert(adyacencias[*it].begin(), adyacencias[*it].end());
                }
                if (adyacencias[i].size() + 1 > mayor) {
                        mayor = adyacencias[i].size() + 1;
                }
        }

        cout << mayor << '\n';
        
        return 0;
}

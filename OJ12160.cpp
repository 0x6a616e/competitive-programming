#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main()
{
        int L, U, R, v, caso = 0;
        vector<int> Ri;
        queue<int> progreso;
        map<int, int> usos;
        while (cin >> L >> U >> R && !(L == 0 && U == 0 && R == 0)) {
                caso++;
                Ri.clear();
                Ri.resize(R, 0);
                usos.clear();
                while (!progreso.empty())
                        progreso.pop();

                for (int i = 0; i < R; i++)
                        cin >> Ri[i];
                
                if (L == U)
                        cout << "0\n";
                else {
                        progreso.push(L);
                        while (!progreso.empty()) {
                                L = progreso.front();
                                progreso.pop();
                                if (L == U)
                                        break;
                                for (int i = 0; i < R; i++) {
                                        v = (L + Ri[i]) % 10000;
                                        if (usos[v] == 0 && usos[L] <= 10000) {
                                                usos[v] = usos[L] + 1;
                                                progreso.push(v);
                                        }
                                }
                        }
                }
        }
        return 0;
}

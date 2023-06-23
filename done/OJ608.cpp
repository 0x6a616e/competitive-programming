#include <bits/stdc++.h>

using namespace std;

int main() {
        cin.tie(0);
        ios::sync_with_stdio(0);

        int n;

        cin >> n;

        while (n--) {
                string izq, der, res;
                map<char, int> contador;
                map<char, bool> seguros;

                for (int i = 0; i < 3; i++) {
                        cin >> izq >> der >> res;

                        if (res == "even") {
                                for (size_t j = 0; j < izq.size(); j++) {
                                        contador[izq[j]] = 0;
                                        seguros[izq[j]] = true;
                                }
                                for (size_t j = 0; j < der.size(); j++) {
                                        contador[der[j]] = 0;
                                        seguros[der[j]] = true;
                                }
                        } else if (res == "up") {
                                for (size_t j = 0; j < izq.size(); j++) {
                                        contador[izq[j]]--;
                                }
                                for (size_t j = 0; j < der.size(); j++) {
                                        contador[der[j]]++;
                                }
                        } else if (res == "down") {
                                for (size_t j = 0; j < izq.size(); j++) {
                                        contador[izq[j]]++;
                                }
                                for (size_t j = 0; j < der.size(); j++) {
                                        contador[der[j]]--;
                                }
                        }
                }

                pair<char, int> best = { 'Z', 0 };

                for (map<char, int>::iterator it = contador.begin(); it != contador.end(); it++) {
                        if (abs(it->second) > abs(best.second) && !seguros[it->first]) {
                                best.first = it->first;
                                best.second = it->second;
                        }
                }

                if (best.second > 0) {
                        cout << best.first << " is the counterfeit coin and it is light.\n";
                } else {
                        cout << best.first << " is the counterfeit coin and it is heavy.\n";
                }
        }
        
        return 0;
}

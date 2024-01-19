#include <bits/stdc++.h>

using namespace std;

int main() {
        cin.tie(0);
        ios::sync_with_stdio(0);

        int n, c = 0;

        while (cin >> n && n) {
                c++;
                string current, original;
                map<string, string> rangos;

                cin >> original;
                rangos[original] = original;

                for (int i = 0; i < n - 1; i++) {
                        cin >> current;
                        if (stoi(current) == stoi(rangos[original]) + 1) {
                                rangos[original] = current;
                        } else {
                                original = current;
                                rangos[original] = original;
                        }
                }

                cout << "Case " << c << ":\n";
                for (map<string, string>::iterator it = rangos.begin(); it != rangos.end(); it++) {
                        bool different = false;
                        cout << it->first;
                        if (it->first != it->second) {
                                cout << '-';
                                for (size_t i = 0; i < it->first.size(); i++) {
                                        if (it->first[i] != it->second[i]) {
                                                different = true;
                                        }
                                        if (different) {
                                                cout << it->second[i];
                                        }
                                }
                        }
                        cout << '\n';
                }
                cout << '\n';
        }
        
        return 0;
}

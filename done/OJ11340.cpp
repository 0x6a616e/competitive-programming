#include <bits/stdc++.h>

using namespace std;

int main() {
        cin.tie(0);
        ios::sync_with_stdio(0);
        
        int N;
        cin >> N;
        for (int _ = 0; _ < N; _++) {
                int K;
                cin >> K;
                map<char, int> precios;
                char letra;
                for (int i = 0; i < K; i++) {
                        cin >> letra;
                        cin >> precios[letra];
                }
                cin >> K;
                string linea;
                int acum = 0;
                getline(cin, linea);
                for (int i = 0; i < K; i++) {
                        getline(cin, linea);
                        for (size_t j = 0; j < linea.size(); j++) {
                                acum += precios[linea[j]];
                        }
                }
                cout << (acum / 100) << '.' << setfill('0') << setw(2) << (acum % 100) << "$\n";
        }
        
        return 0;
}

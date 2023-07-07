// https://codeforces.com/gym/104375/problem/D

#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        long long ai, a, b, k, n, q, op;
        vector<long long> numeros;
        vector<long long>::iterator it;

        cin >> n >> q;

        while (n--) {
                cin >> ai;
                numeros.push_back(ai);
        }

        sort(numeros.begin(), numeros.end());

        while (q--) {
                cin >> op;
                if (op == 1) {
                        cin >> k;
                        it = lower_bound(numeros.begin(), numeros.end(), k);
                        if (k != *it) {
                                if (k > numeros.back()) {
                                        numeros.push_back(k);
                                } else {
                                        it = upper_bound(numeros.begin(), numeros.end(), k);
                                        *it = k;
                                }
                        }
                } else {
                        cin >> a >> b;
                        long long contador = 0;
                        it = upper_bound(numeros.begin(), numeros.end(), b);
                        for (vector<long long>::iterator i = lower_bound(numeros.begin(), numeros.end(), a); i != it; i++) {
                                contador++;
                        }
                        cout << contador << '\n';
                }
        }

        return 0;
}

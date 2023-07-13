// https://codeforces.com/gym/104120/problem/D

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<unsigned long long, int>, null_type,
             less<pair<unsigned long long, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int M, t;
    unsigned long long A, B;
    vector<unsigned long long> operaciones;
    indexed_set contador;

    cin >> M;

    operaciones.resize(M + 1, 0);

    for (int i = 1; i <= M; i++) {
        cin >> t;
        if (t == 1) {
            cin >> A;
            operaciones[i] = A;
            contador.insert({A, i});
        } else if (t == 2) {
            cin >> B;
            contador.erase({operaciones[B], B});
        } else if (t == 3) {
            cin >> B >> A;
            contador.erase({operaciones[B], B});
            operaciones[B] += A;
            contador.insert({operaciones[B], B});
        } else if (t == 4) {
            cin >> B;
            cout << contador.order_of_key({operaciones[B], 0}) << '\n';
        }
    }

    return 0;
}

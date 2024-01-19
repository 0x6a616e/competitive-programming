#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int dimension;

    while (cin >> dimension) {
        int n = pow(2, dimension);
        vector<int> weights(n, 0);
        vector<int> potencies(n, 0);

        for (int i = 0; i < n; ++i) {
            cin >> weights[i];
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < dimension; ++j) {
                potencies[i] += weights[i ^ (1 << j)];
            }
        }

        int maximo = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < dimension; ++j) {
                maximo = max(maximo, potencies[i] + potencies[i ^ (1 << j)]);
            }
        }

        cout << maximo << '\n';
    }

    return 0;
}

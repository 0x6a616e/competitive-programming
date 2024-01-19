#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    map<int, int> contador;

    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        ++contador[ai];
    }

    int sol = 0;
    for (int i = 1; i <= 2 * n; ++i) {
        if (contador[i] > 1) {
            sol += contador[i] - 1;
            contador[i + 1] += contador[i] - 1;
        }
        contador.erase(i);
    }

    cout << sol << "\n";

    return 0;
}

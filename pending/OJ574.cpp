#include <bits/stdc++.h>

#include <string>

using namespace std;

void solve(vector<int> &actual, int indice, vector<int> &opciones, int target,
           unordered_set<string> &aparecidos) {
    int acum = 0;
    for (int &i : actual) acum += i;
    if (acum == target) {
        string s = "";
        for (int &i : actual) s += to_string(i);
        if (aparecidos.count(s)) return;
        aparecidos.insert(s);
        for (int i = 0; i < (int)actual.size(); ++i)
            cout << (i ? "+" : "") << actual[i];
        cout << '\n';
    } else {
        for (int i = indice; i < (int)opciones.size(); ++i) {
            if (acum + opciones[i] <= target) {
                if (actual.size() && opciones[i] > actual.back()) continue;
                actual.push_back(opciones[i]);
                solve(actual, i + 1, opciones, target, aparecidos);
                actual.pop_back();
            }
        }
    }
}

int main() {
    int t, n;
    while (cin >> t >> n && n) {
        vector<int> opciones(n);
        for (int i = 0; i < n; ++i) cin >> opciones[i];
        sort(opciones.rbegin(), opciones.rend());
        cout << "Sums of " << t << ":\n";
        vector<int> curr;
        curr.reserve(n);
        unordered_set<string> usados;
        solve(curr, 0, opciones, t, usados);
        if (!usados.size()) cout << "NONE\n";
    }
    return 0;
}

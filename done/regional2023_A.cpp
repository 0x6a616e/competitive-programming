#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string dia;
    int n, d;

    cin >> dia >> n;

    int diaSemana;
    if (dia == "Mon") diaSemana = 0;
    if (dia == "Tue") diaSemana = 1;
    if (dia == "Wed") diaSemana = 2;
    if (dia == "Thu") diaSemana = 3;
    if (dia == "Fri") diaSemana = 4;
    if (dia == "Sat") diaSemana = 5;
    if (dia == "Sun") diaSemana = 6;

    int best = -1;
    for (int i = 0; i < n; ++i) {
        cin >> d;
        if (d && (best == -1 || d % 30 > best)) best = d % 30;
    }

    int sol;
    if (best == -1) {
        sol = 30;
    } else if (best == 0) {
        sol = 0;
    } else {
        sol = 30 - best;
    }
    diaSemana = (diaSemana + sol) % 7;
    if (diaSemana == 5) sol += 2;
    if (diaSemana == 6) sol += 1;

    cout << sol << endl;

    return 0;
}

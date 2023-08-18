#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int R, aciertos, tmp, errores;
    string palabra, intento;
    unordered_set<char> p;

    while (cin >> R && R != -1) {
        cin >> palabra >> intento;
        p.clear();
        aciertos = errores = 0;

        for (char c : palabra) p.insert(c);
        for (char c : intento) {
            tmp = p.count(c);
            if (!tmp)
                ++errores;
            else
                p.erase(c);
            if (errores == 7 || !p.size()) break;
        }
        cout << "Round " << R << '\n';
        if (!p.size())
            cout << "You win.\n";
        else if (errores == 7)
            cout << "You lose.\n";
        else
            cout << "You chickened out.\n";
    }

    return 0;
}

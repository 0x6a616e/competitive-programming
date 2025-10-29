#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int g, s, c;
    cin >> g >> s >> c;

    int acum = g * 3 + s * 2 + c;

    string v, t;
    v = "";
    if (acum >= 8) {
        v = "Province";
    } else if (acum >= 5) {
        v = "Duchy";
    } else if (acum >= 2) {
        v = "Estate";
    }
    if (acum >= 6) {
        t = "Gold";
    } else if (acum >= 3) {
        t = "Silver";
    } else {
        t = "Copper";
    }

    cout << v << (v.size() ? " or " : "") << t << endl;

    return 0;
}

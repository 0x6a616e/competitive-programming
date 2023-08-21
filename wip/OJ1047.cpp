#include <bits/stdc++.h>

using namespace std;

bool hasExactlyOneBitSet(int num) {
    return (num != 0) && ((num & (num - 1)) == 0);
}

int countBits(int num) {
    int count = 0;
    while (num > 0) {
        if (num & 1) ++count;
        num >>= 1;
    }
    return count;
}

string printLocations(int num) {
    int n = 1;
    string res = "";
    while (num > 0) {
        if (num & 1) res += (n > 1 ? " " : "") + to_string(n);
        num >>= 1;
        ++n;
    }
    if (res[0] == ' ') res = res.substr(1);
    return res;
}

int main() {
    int planned, accepted, caso = 0;
    while (cin >> planned >> accepted && (planned || accepted)) {
        map<int, int> poblaciones;
        for (int i = 0; i < planned; ++i) cin >> poblaciones[1 << i];
        int commons;
        cin >> commons;
        for (int i = 0; i < commons; ++i) {
            int m;
            cin >> m;
            int n = 0;
            for (int j = 0; j < m; ++j) {
                int common;
                cin >> common;
                n += (1 << (common - 1));
            }
            int t;
            cin >> t;
            poblaciones[n] = t;
            for (map<int, int>::iterator it = poblaciones.begin();
                 it != poblaciones.end(); ++it) {
                if (hasExactlyOneBitSet(it->first) &&
                    (it->first & n) == it->first)
                    it->second -= t;
            }
        }
        pair<int, int> mejor = {0, 0};
        for (int i = 0; i < (1 << planned); ++i) {
            int total = 0;
            if (countBits(i) == accepted) {
                for (pair<int, int> ii : poblaciones) {
                    if (i & ii.first) {
                        total += ii.second;
                    }
                }
                if (total > mejor.second) {
                    mejor.first = i;
                    mejor.second = total;
                }
            }
        }
        if (caso) cout << '\n';
        cout << "Case Number  " << ++caso << '\n';
        cout << "Number of Customers: " << mejor.second << '\n';
        cout << "Locations recommended: " << printLocations(mejor.first)
             << '\n';
    }
    return 0;
}

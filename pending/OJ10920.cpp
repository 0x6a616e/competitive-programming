#include <bits/stdc++.h>

#include <utility>

using namespace std;

pair<int, int> FindInRing(int x, int y, int size, int needle) {
    int curr = size * size;
    for (int i = 0; i < size - 1 && curr != needle; ++i) {
        --y;
        --curr;
    }
    for (int i = 0; i < size - 1 && curr != needle; ++i) {
        --x;
        --curr;
    }
    for (int i = 0; i < size - 1 && curr != needle; ++i) {
        ++y;
        --curr;
    }
    for (int i = 0; i < size - 2 && curr != needle; ++i) {
        ++x;
        --curr;
    }
    return make_pair(x, y);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int s, p;
    pair<int, int> sol;

    while (cin >> s >> p && (s || p)) {
        sol.first = ceil(s / 2.0);
        sol.second = ceil(s / 2.0);
        for (int i = 1; i <= s; i += 2) {
            if (p <= (i * i)) {
                sol = FindInRing(sol.first, sol.second, i, p);
                break;
            } else {
                ++sol.first;
                ++sol.second;
            }
        }
        cout << "Line = " << sol.second << ", column = " << sol.first << ".\n";
    }

    return 0;
}

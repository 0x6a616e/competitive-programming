#include <bits/stdc++.h>

#include <iterator>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    list<int> a;
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        a.emplace_back(ai);
    }
    a.sort();

    auto it = a.begin();
    while (it != a.end() && (int)a.size() > 2) {
        for (; it != a.end(); advance(it, 1)) {
            if (*it != *next(it)) {
                break;
            }
        }
        if (it != a.begin() && *it == *prev(it)) {
            auto p = prev(it);
            *it = *it + 1;
            a.erase(p);
            if (it != a.begin()) advance(it, -1);
        } else {
            advance(it, 1);
        }
    }

    if ((int)a.size() == 2)
        cout << "Y\n";
    else
        cout << "N\n";

    return 0;
}

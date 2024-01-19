#include <bits/stdc++.h>

using namespace std;

int main() {
    int k;

    while (cin >> k) {
        long long x, y;
        y = k;
        vector<pair<long long, long long>> sol;

        do {
            ++y;
            x = (-1 * k * y) / (k - y);
            if ((x * y) / (x + y) == k) {
                sol.push_back({x, y});
            }
        } while (x >= y);
        cout << sol.size() << '\n';
        for (pair<long long, long long> s : sol)
            cout << "1/" << k << " = 1/" << s.first << " + 1/" << s.second
                 << '\n';
    }

    return 0;
}

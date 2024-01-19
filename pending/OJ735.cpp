#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> posibles;
    for (int i = 0; i <= 60; ++i) {
        if (i <= 20 || (i % 2 == 0 && i / 2 <= 20) ||
            (i % 3 == 0 && i / 3 <= 20) || i == 50) {
            posibles.push_back(i);
        }
    }

    int n;
    while (cin >> n && n > 0) {
        int p = 0;
        set<vector<int>> combs;
        int s = (int)posibles.size();
        for (int i = 0; i < s; ++i) {
            for (int j = 0; j < s; ++j) {
                for (int k = 0; k < s; ++k) {
                    if (posibles[i] + posibles[j] + posibles[k] == n) {
                        ++p;
                        vector<int> tmp = {i, j, k};
                        sort(tmp.begin(), tmp.end());
                        combs.insert(tmp);
                    }
                }
            }
        }
        if (p != 0 || combs.size() != 0) {
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS "
                 << combs.size() << ".\n";

            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << p
                 << ".\n";
        } else {
            cout << "THE SCORE OF " << n
                 << " CANNOT BE MADE WITH THREE DARTS.\n";
        }
        cout << string(70, '*') << '\n';
    }
    cout << "END OF OUTPUT\n";

    return 0;
}

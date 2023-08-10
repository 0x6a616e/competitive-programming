#include <bits/stdc++.h>

using namespace std;

int main() {
    int f, r;

    while (cin >> f && f) {
        cin >> r;
        vector<int> front_cluster(f);
        vector<int> rear_cluster(r);

        for (int i = 0; i < f; ++i) cin >> front_cluster[i];
        for (int i = 0; i < r; ++i) cin >> rear_cluster[i];

        vector<int> ratios;

        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < r; ++j) {
                ratios.push_back(rear_cluster[j] / front_cluster[i]);
            }
        }

        sort(ratios.begin(), ratios.end());

        int mejor = 0;

        for (int i = 1; i < (int)ratios.size(); ++i) {
            mejor = max(mejor, ratios[i] / ratios[i - 1]);
        }

        cout << mejor << '\n';
    }

    return 0;
}

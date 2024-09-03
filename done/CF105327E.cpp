#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    pair<int, int> e0, e1, e2, e3;
    e0 = {0, 0};
    e1 = {0, n - 1};
    e2 = {n - 1, n - 1};
    e3 = {n - 1, 0};

    int minVal = -1;
    pair<int, int> minPos = {-1, -1};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int k;
            cin >> k;
            if (minVal == -1 || k < minVal) {
                minVal = k;
                minPos = {i, j};
            }
        }
    }

    if (minPos == e0) cout << "0\n";
    if (minPos == e1) cout << "1\n";
    if (minPos == e2) cout << "2\n";
    if (minPos == e3) cout << "3\n";

    return 0;
}

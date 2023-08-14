#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        vector<vector<int>> city(5, vector<int>(5, 0));
        int n;
        cin >> n;
        int x, y, p;
        for (int i = 0; i < n; ++i) {
            cin >> y >> x >> p;
            city[y][x] = p;
        }

        int minimo = -1;
        vector<int> res(5);
        for (int a = 0; a < 25; ++a) {
            for (int b = a + 1; b < 25; ++b) {
                for (int c = b + 1; c < 25; ++c) {
                    for (int d = c + 1; d < 25; ++d) {
                        for (int e = d + 1; e < 25; ++e) {
                            int config = 0;
                            for (int i = 0; i < 5; ++i) {
                                for (int j = 0; j < 5; ++j) {
                                    int zone = 0;
                                    zone += abs(i - a / 5) + abs(j - a % 5);
                                    zone += abs(i - b / 5) + abs(j - b % 5);
                                    zone += abs(i - c / 5) + abs(j - c % 5);
                                    zone += abs(i - d / 5) + abs(j - d % 5);
                                    zone += abs(i - e / 5) + abs(j - e % 5);
                                    zone *= city[i][j];
                                    config += zone;
                                }
                            }
                            if (minimo == -1 || config < minimo) {
                                res[0] = a;
                                res[1] = b;
                                res[2] = c;
                                res[3] = d;
                                res[4] = e;
                                minimo = config;
                            }
                        }
                    }
                }
            }
        }
        for (int i : res) {
            cout << i << ' ';
        }
        cout << '\n';
    }

    return 0;
}

// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=244&page=show_problem&problem=3399

// Casos
// 0 3, 0 3 -> N
// 0 3, 1 2 -> N
// 0 3, 2 1 -> N
// 0 3, 3 0 -> 3 0
// 1 2, 1 2 -> N
// 1 2, 2 1 -> N
// 1 2, 3 0 -> 3 0
// 2 1, 2 1 -> 2 1
// 2 1, 3 0 -> 2 1
// 3 0, 3 0 -> 0 3

#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int a, b, c, d, e;

        while (cin >> a >> b >> c >> d >> e && (a && b && c && d && e)) {
                vector<bool> usadas(53);
                usadas[a] = usadas[b] = usadas[c] = usadas[d] = usadas[e] = true;
                
                vector<int> hermana = { a, b, c };
                sort(hermana.begin(), hermana.end());

                vector<int> hermano = { d, e };
                sort(hermano.begin(), hermano.end());

                int sol = -1;

                if (hermano[0] < hermana[0] && hermano[1] > hermana[2]) {
                        for (int i = hermana[2]; i < 53 && sol == -1; i++) {
                                if (!usadas[i]) {
                                        sol = i;
                                }
                        }
                } else if ((hermano[0] > hermana[0] && hermano[0] < hermana[1]) && hermano[1] > hermana[2]) {
                        for (int i = hermana[2]; i < 53 && sol == -1; i++) {
                                if (!usadas[i]) {
                                        sol = i;
                                }
                        }
                } else if ((hermano[0] > hermana[1] && hermano[0] < hermana[2]) && (hermano[1] > hermana[1] && hermano[1] < hermana[2])) {
                        for (int i = hermana[1]; i < 53 && sol == -1; i++) {
                                if (!usadas[i]) {
                                        sol = i;
                                }
                        }
                } else if ((hermano[0] > hermana[1] && hermano[0] < hermana[2]) && hermano[1] > hermana[2]) {
                        for (int i = hermana[1]; i < 53 && sol == -1; i++) {
                                if (!usadas[i]) {
                                        sol = i;
                                }
                        }
                } else if (hermano[0] > hermana[2] && hermano[1] > hermana[2]) {
                        for (int i = 1; i < 53 && sol == -1; i++) {
                                if (!usadas[i]) {
                                        sol = i;
                                }
                        }
                }

                cout << sol << '\n';
        }
        
        return 0;
}

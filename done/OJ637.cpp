#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int n;

        while (cin >> n && n) {
                int p = n / 4;
                p += (n % 4 ? 1 : 0);

                int a, b;
                a = p * 4;
                b = 1;

                cout << "Printing order for " << n << " pages:\n";
                for (int i = 0; i < p; i++) {
                        cout << "Sheet " << (i + 1) << ", front: " << ((a > n) ? "Blank" : to_string(a)) << ", " << b << '\n';
                        a--;
                        b++;
                        if (a <= n || b <= n) {
                                cout << "Sheet " << (i + 1) << ", back : "<< b << ", " << ((a > n) ? "Blank" : to_string(a)) << '\n';
                                a--;
                                b++;
                        }
                }
        }
        
        return 0;
}

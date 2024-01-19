#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int n;

        cin >> n;

        while (n--) {
                int s, d;
                cin >> s >> d;

                int y = (d - s) / -2;
                int x = s - y;

                if ((d - s) <= 0 && (d - s) % 2 == 0 && x >= 0) {
                        cout << x << ' ' << y << '\n';
                } else {
                        cout << "impossible\n";
                }
        }
        
        return 0;
}

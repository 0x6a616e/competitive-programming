#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int r, c;

        while (cin >> r >> c && (r || c)) {
                if (r == 1 || c == 1) {
                        cout << r * c << " knights may be placed on a " << r << " row " << c << " column board.\n";
                } else if (r == 2 || c == 2) {
                        int sol = 0;

                        if (r == 2) {
                                int cc = c;
                                while (cc > 0) {
                                        sol += min(2, cc) * 2;
                                        cc -= 4;
                                }
                        } else {
                                int rr = r;
                                while (rr > 0) {
                                        sol += min(2, rr) * 2;
                                        rr -= 4;
                                }
                        }

                        cout << sol << " knights may be placed on a " << r << " row " << c << " column board.\n";
                } else {
                        cout << ceil((r * c) / 2.0) << " knights may be placed on a " << r << " row " << c << " column board.\n";
                }
        }
        
        return 0;
}
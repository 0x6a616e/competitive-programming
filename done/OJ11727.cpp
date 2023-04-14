#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int casos;
        vector<int> sueldos(3);

        cin >> casos;

        for (int i = 0; i < casos; i++) {
                cin >> sueldos[0];
                cin >> sueldos[1];
                cin >> sueldos[2];
                sort(sueldos.begin(), sueldos.end());
                cout  << "Case " << i + 1 << ": " << sueldos[1] << '\n';
        }
        
        return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int d;
        cin >> d;

        vector<pair<int, int>> price_db(d);
        vector<string> name_db(d);

        for (int i = 0; i < d; ++i) {
            cin >> name_db[i];
            cin >> price_db[i].first;
            cin >> price_db[i].second;
        }

        int q, p;
        string res;
        cin >> q;

        for (int i = 0; i < q; ++i) {
            res = "";
            cin >> p;
            for (int j = 0; j < d; ++j) {
                if (p >= price_db[j].first && p <= price_db[j].second) {
                    if (res == "") {
                        res = name_db[j];
                    } else {
                        res = "UNDETERMINED";
                    }
                }
            }
            if (res == "") res = "UNDETERMINED";
            cout << res << '\n';
        }
        if (t) cout << '\n';
    }

    return 0;
}

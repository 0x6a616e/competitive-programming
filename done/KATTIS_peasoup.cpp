#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    string ans = "";
    while (n--) {
        int k;
        cin >> k;
        string name;
        getline(cin, name);
        getline(cin, name);
        int c = 0;
        while (k--) {
            string plate;
            getline(cin, plate);
            if (plate == "pea soup") {
                c |= 1;
            }
            if (plate == "pancakes") {
                c |= 2;
            }
        }
        if (ans == "" && c == 3) {
            ans = name;
        }
    }
    cout << (ans.size() ? ans : "Anywhere is fine I guess") << '\n';

    return 0;
}

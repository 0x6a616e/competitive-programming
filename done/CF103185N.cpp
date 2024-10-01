#include <bits/stdc++.h>

using namespace std;

int getCents(string amount) {
    string cents = amount.substr(amount.size() - 2);
    return stoi(cents);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    string start_amount;
    cin >> start_amount;
    int start_cents = getCents(start_amount);

    int sol = 0;
    for (int i = 0; i < n; ++i) {
        string amount;
        cin >> amount;
        int cents = getCents(amount);
        start_cents = (start_cents + cents) % 100;
        if (start_cents != 0) ++sol;
    }

    cout << sol << endl;

    return 0;
}

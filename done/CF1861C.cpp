#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        bool posible = true;

        vector<int> arr;
        arr.reserve(s.size());

        int lastUpdated = 0;

        for (char &c : s) {
            if (c == '-') {
                arr.pop_back();
                lastUpdated = min((int)arr.size(), lastUpdated);
            } else if (c == '+') {
                if (arr.size() && arr.back() == 0)
                    arr.push_back(0);
                else
                    arr.push_back(-1);
            } else if (c == '0') {
                if (arr.size() < 2) posible = false;
                if (arr.size() && arr.back() == 1) posible = false;
                if (arr.size()) arr.back() = 0;
            } else if (c == '1') {
                if (arr.size() && arr.back() == 0) posible = false;
                for (size_t i = lastUpdated; i < arr.size(); ++i) {
                    arr[i] = 1;
                }
                lastUpdated = arr.size();
            }
            if (!posible) break;
        }

        if (posible)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}

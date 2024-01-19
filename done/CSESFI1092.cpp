// https://cses.fi/problemset/task/1092

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    if (n < 3) {
        cout << "NO\n";
    } else {
        int curr;
        vector<int> a1, a2;
        a1.reserve(n);
        a2.reserve(n);
        if (n % 2 == 0) {
            curr = 4;
            a1 = {1, 4};
            a2 = {2, 3};
        } else {
            curr = 3;
            a1 = {1, 2};
            a2 = {3};
        }
        while (curr < n) {
            a1.push_back(curr + 1);
            a1.push_back(curr + 4);
            a2.push_back(curr + 2);
            a2.push_back(curr + 3);
            curr += 4;
        }
        if (curr == n) {
            cout << "YES\n";
            cout << a1.size() << '\n';
            for (int i : a1) cout << i << ' ';
            cout << '\n' << a2.size() << '\n';
            for (int i : a2) cout << i << ' ';
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

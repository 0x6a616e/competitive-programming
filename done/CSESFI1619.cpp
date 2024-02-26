// https://cses.fi/problemset/task/1619

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<pair<int, char>> arr;
    arr.reserve(2 * n);
    int a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        arr.push_back({a, 'E'});
        arr.push_back({b, 'S'});
    }

    sort(arr.begin(), arr.end());
    int curr = 0;
    int best = 0;
    for (pair<int, char> person : arr) {
        if (person.second == 'E') {
            ++curr;
        } else {
            --curr;
        }
        best = max(best, curr);
    }

    cout << best << endl;

    return 0;
}

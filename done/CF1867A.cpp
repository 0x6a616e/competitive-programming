// https://codeforces.com/contest/1867/problem/A

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int num;

        int curr = 1;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; ++i) {
            cin >> num;
            pq.push({num, i});
        }

        int nums[n];
        while (!pq.empty()) {
            nums[pq.top().second] = curr++;
            pq.pop();
        }

        for (int i = 0; i < n; ++i) cout << nums[i] << ' ';
        cout << '\n';
    }

    return 0;
}

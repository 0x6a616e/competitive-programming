#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        pq.push(a);
    }
    vector<int> ans;
    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        if (a == b) {
            pq.push(a + 1);
        } else {
            ans.push_back(a);
            pq.push(b);
        }
    }
    if (n > 1 && ans.size() + pq.size() < 3) {
        cout << "Y\n";
    } else {
        cout << "N\n";
    }

    return 0;
}

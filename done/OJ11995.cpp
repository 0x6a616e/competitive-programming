#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;

    while (cin >> n) {
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        int op, x;
        int counter, s_counter, q_counter, pq_counter;
        counter = s_counter = q_counter = pq_counter = 0;

        for (int i = 0; i < n; ++i) {
            cin >> op >> x;
            if (op == 1) {
                s.push(x);
                q.push(x);
                pq.push(x);
            } else {
                ++counter;
                if (!s.empty()) {
                    if (s.top() == x) {
                        ++s_counter;
                    }
                    s.pop();
                }
                if (!q.empty()) {
                    if (q.front() == x) {
                        ++q_counter;
                    }
                    q.pop();
                }
                if (!pq.empty()) {
                    if (pq.top() == x) {
                        ++pq_counter;
                    }
                    pq.pop();
                }
            }
        }

        int res = 0;

        if (counter == s_counter) {
            res = res | 1;
        }
        if (counter == q_counter) {
            res = res | (1 << 1);
        }
        if (counter == pq_counter) {
            res = res | (1 << 2);
        }

        if (res == 0) {
            cout << "impossible\n";
        } else if (res == 1) {
            cout << "stack\n";
        } else if (res == 2) {
            cout << "queue\n";
        } else if (res == 4) {
            cout << "priority queue\n";
        } else {
            cout << "not sure\n";
        }
    }

    return 0;
}

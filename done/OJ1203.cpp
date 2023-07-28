#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string instruction;
    int q_num, period;
    unordered_map<int, int> periods;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        print_queue;

    while (cin >> instruction && instruction != "#") {
        cin >> q_num >> period;
        periods[q_num] = period;
        print_queue.push({period, q_num});
    }

    int k;

    cin >> k;

    for (int i = 0; i < k; ++i) {
        q_num = print_queue.top().second;
        period = print_queue.top().first;

        print_queue.pop();
        print_queue.push({period + periods[q_num], q_num});

        cout << q_num << '\n';
    }

    return 0;
}

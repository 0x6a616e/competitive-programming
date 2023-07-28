#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int c;

    cin >> c;

    while (c--) {
        int n, t, m;

        cin >> n >> t >> m;

        vector<queue<int>> sides(2);
        int arrival_time;
        string arrival_side;
        vector<int> times;

        for (int i = 0; i < m; ++i) {
            cin >> arrival_time >> arrival_side;
            if (arrival_side == "left") {
                sides[0].push(i);
            } else {
                sides[1].push(i);
            }
            times.push_back(arrival_time);
        }

        queue<int> ferry;
        int current_side = 0;
        int current_time = 0;

        while (!ferry.empty() || !sides[0].empty() || !sides[1].empty()) {
            while (!ferry.empty()) {
                int car = ferry.front();
                times[car] = current_time;
                ferry.pop();
            }
            while (ferry.size() < n &&
                   (!sides[current_side].empty() &&
                    times[sides[current_side].front()] <= current_time)) {
                ferry.push(sides[current_side].front());
                sides[current_side].pop();
            }
            if (!ferry.empty() ||
                (!sides[(current_side + 1) % 2].empty() &&
                 times[sides[(current_side + 1) % 2].front()] <=
                     current_time)) {
                current_side = (current_side + 1) % 2;
                current_time += t;
            } else {
                ++current_time;
            }
        }

        for (int i = 0; i < m; ++i) {
            cout << times[i] << '\n';
        }
        if (c > 0) {
            cout << '\n';
        }
    }

    return 0;
}

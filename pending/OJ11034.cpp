#include <iostream>
#include <queue>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int c;

    cin >> c;

    while (c--) {
        int l, m;

        cin >> l >> m;

        vector<queue<int>> sides(2);
        int car_length;
        string arrival_side;

        for (int i = 0; i < m; ++i) {
            cin >> car_length >> arrival_side;

            if (arrival_side == "left") {
                sides[0].push(car_length);
            } else {
                sides[1].push(car_length);
            }
        }

        int current_side = 0;
        l *= 100;
        int original_l = l;
        int counter = 0;

        while (!sides[0].empty() || !sides[1].empty()) {
            l = original_l;
            while (!sides[current_side].empty() &&
                   sides[current_side].front() <= l) {
                l -= sides[current_side].front();
                sides[current_side].pop();
            }
            if (l != original_l || !sides[(current_side + 1) % 2].empty()) {
                ++counter;
                current_side = (current_side + 1) % 2;
            }
        }

        cout << counter << '\n';
    }

    return 0;
}

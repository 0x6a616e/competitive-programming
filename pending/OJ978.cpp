#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int c;

    cin >> c;

    while (c--) {
        int b, sg, sb;

        cin >> b >> sg >> sb;

        priority_queue<int> green_soldiers;
        queue<int> green_reserves;

        priority_queue<int> blue_soldiers;
        queue<int> blue_reserves;

        int soldier;
        for (int i = 0; i < sg; ++i) {
            cin >> soldier;
            green_soldiers.push(soldier);
        }
        for (int i = 0; i < sb; ++i) {
            cin >> soldier;
            blue_soldiers.push(soldier);
        }

        while (!green_soldiers.empty() && !blue_soldiers.empty()) {
            int current_g, current_b;
            for (int i = 0;
                 i < b && (!green_soldiers.empty() && !blue_soldiers.empty());
                 ++i) {
                current_g = green_soldiers.top();
                green_soldiers.pop();

                current_b = blue_soldiers.top();
                blue_soldiers.pop();

                if (current_g > current_b) {
                    green_reserves.push(current_g - current_b);
                } else if (current_b > current_g) {
                    blue_reserves.push(current_b - current_g);
                }
            }

            while (!green_reserves.empty()) {
                green_soldiers.push(green_reserves.front());
                green_reserves.pop();
            }
            while (!blue_reserves.empty()) {
                blue_soldiers.push(blue_reserves.front());
                blue_reserves.pop();
            }
        }

        if (green_soldiers.empty() && blue_soldiers.empty()) {
            cout << "green and blue died\n";
        } else if (!green_soldiers.empty()) {
            cout << "green wins\n";
            while (!green_soldiers.empty()) {
                cout << green_soldiers.top() << '\n';
                green_soldiers.pop();
            }
        } else if (!blue_soldiers.empty()) {
            cout << "blue wins\n";
            while (!blue_soldiers.empty()) {
                cout << blue_soldiers.top() << '\n';
                blue_soldiers.pop();
            }
        }

        if (c > 0) {
            cout << '\n';
        }
    }

    return 0;
}

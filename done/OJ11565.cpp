#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    int A, B, C;
    for (int i = 0; i < N; ++i) {
        cin >> A >> B >> C;
        bool posible = false;
        for (int x = -1000; x < A && !posible; ++x) {
            for (int y = x + 1; x + y < A && !posible; ++y) {
                int z = A - x - y;
                if (z <= y) continue;
                if (!posible && x * y * z == B && x * x + y * y + z * z == C) {
                    cout << x << ' ' << y << ' ' << z << '\n';
                    posible = true;
                }
            }
        }

        if (!posible) cout << "No solution.\n";
    }

    return 0;
}

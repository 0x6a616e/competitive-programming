// https://codeforces.com/problemset/problem/40/A

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int x, y;
    cin >> x >> y;

    char color;
    if (x == 0 || y == 0)
        cout << "black\n";
    else {
        if (x > 0 && y > 0) color = 'b';
        if (x > 0 && y < 0) color = 'w';
        if (x < 0 && y > 0) color = 'w';
        if (x < 0 && y < 0) color = 'b';

        double dist = sqrt(x * x + y * y);
        while (dist > 1) {
            color = (color == 'b' ? 'w' : 'b');
            --dist;
        }
        if (dist == 1) color = 'b';
        if (color == 'b') cout << "black\n";
        if (color == 'w') cout << "white\n";
    }

    return 0;
}

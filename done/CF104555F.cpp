// https://codeforces.com/gym/104555/problem/F

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int d, c, r;
    cin >> d >> c >> r;

    queue<int> cansa;
    queue<int> rejuvenece;

    for (int i = 0; i < c; ++i) {
        int n;
        cin >> n;
        cansa.push(n);
    }
    for (int i = 0; i < r; ++i) {
        int n;
        cin >> n;
        rejuvenece.push(n);
    }

    int sol = 0;
    while (!rejuvenece.empty() || (!cansa.empty() && d >= cansa.front())) {
        if (!cansa.empty() && d >= cansa.front()) {
            d -= cansa.front();
            cansa.pop();
        } else {
            d += rejuvenece.front();
            rejuvenece.pop();
        }
        ++sol;
    }

    cout << sol << endl;

    return 0;
}

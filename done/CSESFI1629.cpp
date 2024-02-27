// https://cses.fi/problemset/task/1629

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    pair<int, int> movies[n];
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        movies[i] = {b, a};
    }
    sort(movies, movies + n);
    int curr = 0;
    int sol = 0;
    for (pair<int, int> movie : movies) {
        if (movie.second >= curr) {
            ++sol;
            curr = movie.first;
        }
    }

    cout << sol << '\n';

    return 0;
}

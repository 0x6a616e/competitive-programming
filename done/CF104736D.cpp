// https://codeforces.com/gym/104736/problem/D

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    string goal = "";
    string curr;
    map<string, int> contador;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> curr;
        if (goal == "") goal = curr;

        string transformation = "XXXXX";
        for (int j = 0; j < 5; ++j)
            if (curr[j] == goal[j]) transformation[j] = '*';

        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k < 5; ++k) {
                if (j == k) continue;
                if (curr[j] == goal[k]) transformation[j] = '!';
            }
        }

        ++contador[transformation];
    }

    int g;
    cin >> g;

    for (int i = 0; i < g; ++i) {
        cin >> curr;
        cout << contador[curr] << '\n';
    }

    return 0;
}

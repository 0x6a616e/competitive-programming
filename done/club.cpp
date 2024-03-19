// https://www.codechef.com/problems/H1

#include <bits/stdc++.h>

using namespace std;

map<string, pair<int, bool>> memo;
set<int> primes = {2, 3, 5, 7, 11, 13, 17};
vector<pair<int, int>> changes = {{0, 1}, {0, 3}, {1, 2}, {1, 4}, {2, 5}, {3, 4},
                                  {3, 6}, {4, 5}, {4, 7}, {5, 8}, {6, 7}, {7, 8}};

void fillMap() {
    queue<pair<string, int>> pending;
    pending.push({"123456789", 0});

    pair<string, int> current;
    while (!pending.empty()) {
        current = pending.front();
        pending.pop();
        if (!memo[current.first].second) {
            memo[current.first] = {current.second, true};
            for (pair<int, int> change : changes) {
                int i = change.first;
                int j = change.second;
                if (primes.count(current.first[i] - '0' + current.first[j] - '0')) {
                    swap(current.first[i], current.first[j]);
                    pending.push({current.first, current.second + 1});
                    swap(current.first[i], current.first[j]);
                }
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    fillMap();

    int t;
    cin >> t;

    while (t--) {
        string attempt = "";
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int n;
                cin >> n;
                attempt += '0' + n;
            }
        }

        if (memo[attempt].second == true) {
            cout << memo[attempt].first << '\n';
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}

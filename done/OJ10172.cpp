#include <iostream>
#include <queue>
#include <stack>

using namespace std;

bool AllStationsEmpty(vector<queue<int>> &stations) {
    for (size_t i = 0; i < stations.size(); ++i) {
        if (stations[i].size()) {
            return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;

    cin >> t;

    while (t--) {
        int n, s, q;

        cin >> n >> s >> q;

        vector<queue<int>> stations(n);
        stack<int> carrier;

        for (int i = 0; i < n; ++i) {
            int queue_size, tag;

            cin >> queue_size;

            for (int j = 0; j < queue_size; ++j) {
                cin >> tag;
                stations[i].push(tag);
            }
        }
        int current_station = 0;
        int time_used = 0;

        while (!carrier.empty() || !AllStationsEmpty(stations)) {
            while (!carrier.empty() &&
                   (stations[current_station].size() < q ||
                    carrier.top() == (current_station + 1))) {
                ++time_used;
                if (carrier.top() != (current_station + 1)) {
                    stations[current_station].push(carrier.top());
                }
                carrier.pop();
            }

            while (!stations[current_station].empty() && carrier.size() < s) {
                ++time_used;
                carrier.push(stations[current_station].front());
                stations[current_station].pop();
            }

            time_used += 2;
            current_station = (current_station + 1) % n;
        }
        time_used -= 2;

        cout << time_used << '\n';
    }

    return 0;
}

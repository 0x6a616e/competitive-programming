#include <bits/stdc++.h>

using namespace std;

bool LeaderboardSort(vector<int> &a, vector<int> &b) {
    if (a[1] != b[1]) {
        return a[1] > b[1];
    }
    if (a[2] != b[2]) {
        return a[2] < b[2];
    }
    return a[0] < b[0];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    string line;

    cin >> t;
    getline(cin, line);
    getline(cin, line);

    while (t--) {
        string contestant, problem, veredict, time_read;
        int time_taken;
        istringstream line_stream;
        map<string, map<string, int>> fails;
        map<string, pair<int, int>> unsorted_results;
        vector<bool> appeared(101, false);

        while (getline(cin, line) && line != "") {
            line_stream.str(line + "\n");
            getline(line_stream, contestant, ' ');
            getline(line_stream, problem, ' ');
            getline(line_stream, time_read, ' ');
            time_taken = stoi(time_read);
            getline(line_stream, veredict);

            if (!appeared[stoi(contestant)]) {
                unsorted_results[contestant] = {0, 0};
                appeared[stoi(contestant)] = true;
            }

            if (fails[contestant][problem] == -1) {
                continue;
            }

            if (veredict == "I") {
                ++fails[contestant][problem];
            } else if (veredict == "C") {
                ++unsorted_results[contestant].first;
                unsorted_results[contestant].second +=
                    time_taken + fails[contestant][problem] * 20;
                fails[contestant][problem] = -1;
            }
        }

        map<string, pair<int, int>>::iterator it;
        vector<vector<int>> sorted_results;
        for (it = unsorted_results.begin(); it != unsorted_results.end();
             ++it) {
            sorted_results.push_back(
                {stoi(it->first), it->second.first, it->second.second});
        }
        sort(sorted_results.begin(), sorted_results.end(), LeaderboardSort);

        for (size_t i = 0; i < sorted_results.size(); ++i) {
            cout << sorted_results[i][0] << ' ' << sorted_results[i][1] << ' '
                 << sorted_results[i][2] << '\n';
        }
        if (t > 0) {
            cout << '\n';
        }
    }

    return 0;
}

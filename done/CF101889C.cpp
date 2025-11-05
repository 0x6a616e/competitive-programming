#include <bits/stdc++.h>

using namespace std;

bool comparator(pair<int, int> &a, pair<int, int> &b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int k, n;
    cin >> k >> n;
    vector<int> freq(k + 1, 0);
    for (int i = 0; i < n; ++i) {
        int s;
        cin >> s;
        ++freq[s];
    }
    map<int, int> freq_freq;
    for (int i = 1; i <= k; ++i) ++freq_freq[freq[i]];

    pair<int, int> ans = {0, 0};
    vector<pair<int, int>> pairs;
    for (pair<int, int> p : freq_freq) pairs.push_back(p);
    sort(pairs.begin(), pairs.end(), comparator);
    if (freq_freq.size() == 2) {
        if (pairs[0].second == 1 && pairs[0].first + 1 == pairs[1].first) {
            for (int i = 1; i <= k; ++i) {
                if (freq[i] == pairs[0].first) {
                    ans = {i, 0};
                    break;
                }
            }
        } else if (pairs[0].second == 1 && pairs[0].first - 1 == pairs[1].first) {
            for (int i = 1; i <= k; ++i) {
                if (freq[i] == pairs[0].first) {
                    ans = {-1 * i, 0};
                    break;
                }
            }
        } else if (pairs[0].second == 1 && pairs[1].second == 1 && pairs[1].second - pairs[0].second == 2) {
            int a, b;
            for (int i = 1; i <= k; ++i) {
                if (freq[i] == pairs[0].first) a = i;
                if (freq[i] == pairs[1].first) b = i;
            }
            ans = {-1 * b, a};
        }
    } else if (freq_freq.size() == 3) {
        sort(pairs.begin(), pairs.end());
        if (pairs[0].second == 1 && pairs[2].second == 1 && pairs[0].first + 1 == pairs[1].first && pairs[2].first - 1 == pairs[1].first) {
            int a, b;
            for (int i = 1; i <= k; ++i) {
                if (freq[i] == pairs[0].first) a = i;
                if (freq[i] == pairs[2].first) b = i;
            }
            ans = {-1 * b, a};
        }
    }
    if (ans.first == 0) {
        cout << "*\n";
    } else {
        cout << (ans.first > 0 ? "+" : "-") << abs(ans.first);
        if (ans.second != 0) cout << (ans.second > 0 ? " +" : " -") << abs(ans.second);
        cout << endl;
    }

    return 0;
}

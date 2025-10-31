#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int c;
    cin >> c;
    for (int i = 0; i < c; ++i) {
        string s, t;
        cin >> s >> t;
        int ans = 0;

        pair<int, int> s_c = {0, 0};
        pair<int, int> t_c = {0, 0};
        for (int j = 0; j < (int)s.size(); ++j) {
            if (s[j] == '0') {
                ++s_c.first;
            } else if (s[j] == '1') {
                ++s_c.second;
            }
            if (t[j] == '0') {
                ++t_c.first;
            } else {
                ++t_c.second;
            }
        }

        if (s_c.second > t_c.second) {
            cout << "Case " << i + 1 << ": -1\n";
            continue;
        }

        int m_0 = t_c.first - s_c.first;
        int m_1 = t_c.second - s_c.second;
        for (int j = 0; j < (int)s.size(); ++j) {
            if (m_1 > 0 && s[j] == '?' && t[j] == '1') {
                s[j] = '1';
                ++ans;
                --m_1;
            }
        }
        for (int j = 0; j < (int)s.size(); ++j) {
            if (m_0 > 0 && s[j] == '?' && t[j] == '0') {
                s[j] = '0';
                ++ans;
                --m_0;
            }
        }
        for (int j = 0; j < (int)s.size(); ++j) {
            if (s[j] == '?') {
                if (m_0 > 0) {
                    s[j] = '0';
                    ++ans;
                    --m_0;
                } else if (m_1 > 0) {
                    s[j] = '1';
                    ++ans;
                    --m_1;
                }
            }
        }
        for (int j = 0; j < (int)s.size(); ++j) {
            if (m_1 > 0 && s[j] == '0' && t[j] == '1') {
                s[j] = '1';
                ++ans;
                --m_1;
            }
        }
        for (int j = 0; j < (int)s.size(); ++j) {
            if (m_1 > 0 && s[j] == '0' && t[j] == '0') {
                s[j] = '1';
                ++ans;
                --m_1;
            }
        }
        int count = 0;
        for (int j = 0; j < (int)s.size(); ++j) {
            if (s[j] != t[j]) {
                ++count;
            }
        }

        ans += count / 2;

        cout << "Case " << i + 1 << ": " << ans << '\n';
    }

    return 0;
}

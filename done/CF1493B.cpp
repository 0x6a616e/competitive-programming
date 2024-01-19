// https://codeforces.com/problemset/problem/1493/B

#include <bits/stdc++.h>

using namespace std;

struct Hour {
    vector<int> digits;
    int h, m;

    Hour(int &h, int &m, char &h1, char &h2, char &_, char &m1, char &m2) {
        digits = {h1 - '0', h2 - '0', m1 - '0', m2 - '0'};
        this->h = h;
        this->m = m;
    }

    pair<int, int> getCurr() {
        return {digits[0] * 10 + digits[1], digits[2] * 10 + digits[3]};
    }

    pair<int, int> getMirror() {
        vector<int> digitsMirror = {0, 0, 0, 0};
        map<int, int> mirrorer;
        mirrorer[0] = 0;
        mirrorer[1] = 1;
        mirrorer[2] = 5;
        mirrorer[5] = 2;
        mirrorer[8] = 8;
        for (int i = 0; i < 4; ++i) {
            if (!mirrorer.count(digits[i])) return {-1, -1};
            digitsMirror[i] = mirrorer[digits[i]];
        }
        reverse(digitsMirror.begin(), digitsMirror.end());
        return {digitsMirror[0] * 10 + digitsMirror[1],
                digitsMirror[2] * 10 + digitsMirror[3]};
    }

    void passMinute() {
        ++digits[3];
        if (digits[3] == 10) {
            digits[3] = 0;
            ++digits[2];
        }
        if (digits[2] * 10 + digits[3] >= m) {
            digits[2] = 0;
            digits[3] = 0;
            ++digits[1];
        }
        if (digits[1] == 10) {
            digits[1] = 0;
            ++digits[0];
        }
        if (digits[0] * 10 + digits[1] >= h) {
            digits[0] = 0;
            digits[1] = 0;
        }
    }

    void print() {
        cout << digits[0];
        cout << digits[1];
        cout << ':';
        cout << digits[2];
        cout << digits[3];
        cout << '\n';
    }
};

bool validate(pair<int, int> &hour, int &h, int &m) {
    return hour.first < h && hour.second < m;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int h, m;
        char h1, h2, _, m1, m2;
        cin >> h >> m;
        cin >> h1 >> h2 >> _ >> m1 >> m2;

        Hour hour(h, m, h1, h2, _, m1, m2);

        bool flag = false;
        pair<int, int> mirror;

        while (!flag) {
            mirror = hour.getMirror();
            if (mirror.first != -1 && mirror.second != -1 &&
                validate(mirror, h, m)) {
                flag = true;
                hour.print();
            }
            hour.passMinute();
        }
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

struct bigNum {
    int base;
    vector<int> digits;

    bigNum(string num) {
        base = 1000 * 1000 * 1000;
        for (int i = (int)num.length(); i > 0; i -= 9)
            if (i < 9)
                digits.push_back(atoi(num.substr(0, i).c_str()));
            else
                digits.push_back(atoi(num.substr(i - 9, 9).c_str()));
    }

    void add(bigNum &n2) {
        int carry = 0;
        for (size_t i = 0; i < max(digits.size(), n2.digits.size()) || carry;
             ++i) {
            if (i == digits.size()) digits.push_back(0);

            digits[i] += carry + (i < n2.digits.size() ? n2.digits[i] : 0);
            carry = digits[i] >= base;

            if (carry) digits[i] -= base;
        }
        cleanZeros();
    }

    void multiplyBy(int &n2) {
        int carry = 0;
        for (size_t i = 0; i < digits.size() || carry; ++i) {
            if (i == digits.size()) digits.push_back(0);

            long long cur = carry + digits[i] * 1ll * n2;
            digits[i] = int(cur % base);
            carry = int(cur / base);
        }
        cleanZeros();
    }

    void cleanZeros() {
        while (digits.size() > 1 && digits.back() == 0) digits.pop_back();
    }

    bool operator<(bigNum &bn2) {
        if (digits.size() != bn2.digits.size())
            return digits.size() < bn2.digits.size();

        for (int i = (int)digits.size() - 1; i >= 0; --i)
            if (digits[i] != bn2.digits[i]) return digits[i] < bn2.digits[i];

        return false;
    }

    void print() {
        if (digits.empty()) {
            cout << 0;
        } else {
            cout << digits.back();
        }

        for (int i = (int)digits.size() - 2; i >= 0; --i) {
            cout << setw(9) << setfill('0') << digits[i];
        }
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    string k;

    while (cin >> n >> m >> k) {
        vector<int> patron(m);
        for (int i = 0; i < m; ++i) cin >> patron[i];
    }

    return 0;
}

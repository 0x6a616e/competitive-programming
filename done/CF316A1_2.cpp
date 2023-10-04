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

    void multiplyBy(int n2) {
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

    string s, s2 = "";
    cin >> s;

    set<char> letras;
    for (int i = 0; i < 26; ++i) letras.insert('A' + i);

    set<char> digitos;
    for (int i = 0; i < 10; ++i) digitos.insert('0' + i);

    set<char> aparecidos;
    for (char &c : s) {
        if (letras.count(c) && aparecidos.count(c)) continue;
        if (letras.count(c)) aparecidos.insert(c);
        s2 += c;
    }

    s = s2;

    bigNum sol("1");
    int curr = 10;

    if (s[0] == '?') {
        sol.multiplyBy(9);
    } else if (letras.count(s[0])) {
        sol.multiplyBy(9);
        --curr;
    }

    string zeroes = "";
    for (int i = 1; i < (int)s.size(); ++i) {
        if (s[i] == '?') {
            zeroes += '0';
        } else if (letras.count(s[i])) {
            sol.multiplyBy(curr--);
        }
    }

    sol.print();
    cout << zeroes << endl;

    return 0;
}

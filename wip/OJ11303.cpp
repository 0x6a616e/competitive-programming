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

    void print() {
        for (int &digit : digits) cout << digit << ' ';
        cout << endl;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    bigNum bn("12345678901234567890123456789012345678901234567890");

    bn.print();

    return 0;
}

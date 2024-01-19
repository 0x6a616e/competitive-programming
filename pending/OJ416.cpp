#include <bits/stdc++.h>

using namespace std;

bool valido(string &original, string &intento, int &quemados) {
    bool v = true;
    for (int i = 0; i < 8; ++i) {
        if (quemados & (1 << i)) original[i] = 'N';
        if (intento[i] == 'Y' && original[i] != 'Y') v = false;
        if (original[i] == 'Y' && intento[i] != 'Y') quemados |= (1 << i);
    }

    return v;
}

bool solve(vector<string> &input, vector<string> lights, int n) {
    int quemados = 0;
    for (int i = 0; i < (int)input.size(); ++i)
        if (!valido(lights[n - i], input[i], quemados)) return false;

    return true;
}

int main() {
    vector<string> nums_str = {"YYYYYYN", "NYYNNNN", "YYNYYNY", "YYYYNNY",
                               "NYYNNYY", "YNYYNYY", "YNYYYYY", "YYYNNNN",
                               "YYYYYYY", "YYYYNYY"};

    int n;
    while (cin >> n && n) {
        vector<string> input(n);
        for (int i = 0; i < n; ++i) cin >> input[i];
        bool posible = false;
        for (int i = n - 1; i < 10 && !posible; ++i)
            if (solve(input, nums_str, i)) posible = true;
        if (posible)
            cout << "MATCH\n";
        else
            cout << "MISMATCH\n";
    }

    return 0;
}

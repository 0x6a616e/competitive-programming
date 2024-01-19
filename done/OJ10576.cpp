#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &months, int s, int d) {
    if (months.size() == 12) {
        int acum = 0;
        for (int i = 0; i < 8; ++i) {
            int sum = 0;
            for (int j = 0; j < 5; ++j) sum += months[i + j];
            if (sum > 0) return 0;
        }
        for (int &i : months) acum += i;
        return acum;
    }
    months.push_back(s);
    int a = solve(months, s, d);
    months.pop_back();
    months.push_back(-d);
    int b = solve(months, s, d);
    months.pop_back();
    return max(a, b);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int s, d;

    while (cin >> s >> d) {
        vector<int> months;
        months.reserve(12);
        int res = solve(months, s, d);
        if (res)
            cout << res << '\n';
        else
            cout << "Deficit\n";
    }

    return 0;
}

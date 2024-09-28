#include <bits/stdc++.h>

using namespace std;

void method1(int &sol_t, vector<pair<int, int>> &sol, vector<int> &left) {
    sol_t += left.back() + left[1] * 2 + left[0];
    sol.push_back({left[0], left[1]});
    sol.push_back({left[0], -1});
    sol.push_back({left[(int)left.size() - 2], left.back()});
    sol.push_back({left[1], -1});
    left.pop_back();
    left.pop_back();
}

void method2(int &sol_t, vector<pair<int, int>> &sol, vector<int> &left) {
    sol_t += left.back() + left[(int)left.size() - 2] + left[0] * 2;
    sol.push_back({left[0], left.back()});
    sol.push_back({left[0], -1});
    left.pop_back();
    sol.push_back({left[0], left.back()});
    sol.push_back({left[0], -1});
    left.pop_back();
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    for (int case_n = 0; case_n < t; ++case_n) {
        if (case_n != 0) cout << endl;

        int n;
        cin >> n;
        vector<int> left(n);
        for (int i = 0; i < n; ++i) cin >> left[i];
        sort(left.begin(), left.end());

        int sol_t = 0;
        vector<pair<int, int>> sol;
        while (!left.empty()) {
            switch (left.size()) {
                case 1:
                    sol_t += left[0];
                    sol.push_back({left[0], -1});
                    left.clear();
                    break;
                case 2:
                    sol_t += left[1];
                    sol.push_back({left[0], left[1]});
                    left.clear();
                    break;
                case 3:
                    sol_t = accumulate(left.begin(), left.end(), sol_t);
                    sol.push_back({left[0], left[1]});
                    sol.push_back({left[0], -1});
                    sol.push_back({left[0], left[2]});
                    left.clear();
                    break;
                default:
                    int m1 = left.back() + left[1] * 2 + left[0];
                    int m2 = left.back() + left[(int)left.size() - 2] + left[0] * 2;
                    if (m1 <= m2)
                        method1(sol_t, sol, left);
                    else
                        method2(sol_t, sol, left);
            }
        }

        cout << sol_t << endl;
        for (pair<int, int> p : sol) {
            cout << p.first;
            if (p.second != -1) cout << ' ' << p.second;
            cout << endl;
        }
    }

    return 0;
}

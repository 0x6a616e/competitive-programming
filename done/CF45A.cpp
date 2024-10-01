#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    vector<string> months = {"January", "February", "March",     "April",   "May",      "June",
                             "July",    "August",   "September", "October", "November", "December"};

    string month;
    cin >> month;
    int i = 0;
    for (; i < 12; ++i)
        if (months[i] == month) break;
    int k;
    cin >> k;
    cout << months[(i + k) % 12] << endl;

    return 0;
}

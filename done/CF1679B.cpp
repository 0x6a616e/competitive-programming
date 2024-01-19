// https://codeforces.com/problemset/problem/1679/B

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, q;
    cin >> n >> q;

    int lastFirstQuery[n];
    int lastFirstQueryValue[n];
    int lastSecondQuery = -1;
    int lastSecondQueryValue;
    long long curr = 0;
    int nums[n];

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        curr += nums[i];
        lastFirstQuery[i] = -1;
    }

    int op, a, b;
    for (int i = 0; i < q; ++i) {
        cin >> op;
        if (op == 1) {
            cin >> a >> b;
            if (lastFirstQuery[a - 1] == -1 && lastSecondQuery == -1)
                curr -= nums[a - 1];
            else if (lastFirstQuery[a - 1] > lastSecondQuery)
                curr -= lastFirstQueryValue[a - 1];
            else if (lastFirstQuery[a - 1] < lastSecondQuery)
                curr -= lastSecondQueryValue;

            curr += b;
            lastFirstQuery[a - 1] = i;
            lastFirstQueryValue[a - 1] = b;
        } else if (op == 2) {
            cin >> b;
            curr = (long long)n * (long long)b;
            lastSecondQuery = i;
            lastSecondQueryValue = b;
        }

        cout << curr << '\n';
    }

    return 0;
}

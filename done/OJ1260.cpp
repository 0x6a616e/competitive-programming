#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n), B(n - 1, 0);

        for (int i = 0; i < n; ++i) {
            cin >> A[i];
            if (i) {
                for (int j = 0; j < i; ++j) {
                    if (A[j] <= A[i]) {
                        ++B[i - 1];
                    }
                }
            }
        }

        int sol = 0;
        for (int i = 0; i < (int)B.size(); ++i) sol += B[i];
        cout << sol << '\n';
    }

    return 0;
}

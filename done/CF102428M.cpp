#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = N - 1; i > 0; --i) A[i] -= A[i - 1];
    A[0] = 0;
    int mejor = 0;
    int curr = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] <= X)
            ++curr;
        else
            curr = 1;
        mejor = max(mejor, curr);
    }
    cout << mejor << '\n';

    return 0;
}

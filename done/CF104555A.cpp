#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, H;
    cin >> N >> H;
    int c = 0;
    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;
        if (n <= H) ++c;
    }
    cout << c << endl;

    return 0;
}

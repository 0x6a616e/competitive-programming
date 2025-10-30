#include <bits/stdc++.h>

using namespace std;

int digits(int n) {
    int ans = 0;
    while (n) {
        ++ans;
        n /= 10;
    }
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string x0;
    while (cin >> x0) {
        if (x0 == "END") {
            break;
        }
        if (x0 == "1") {
            cout << "1\n";
            continue;
        }
        int i = 1;
        int prev = 0;
        int curr = x0.size();
        while (curr != prev) {
            ++i;
            prev = curr;
            curr = digits(curr);
        }
        cout << i << '\n';
    }

    return 0;
}

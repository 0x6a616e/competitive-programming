#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string line;

    while (cin >> line && line != "#") {
        if (next_permutation(line.begin(), line.end())) {
            cout << line << '\n';
        } else {
            cout << "No Successor\n";
        }
    }

    return 0;
}

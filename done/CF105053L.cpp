#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int R, C, K;
    cin >> R >> C >> K;

    bool possible = true;
    for (int i = 0; i < R && possible; ++i) {
        string l, r;
        cin >> l >> r;
        bool has_errors = false;
        for (char c : l) has_errors = has_errors || c == '-';
        bool use_line = false;
        for (char c : r) use_line = use_line || c == '*';
        if (has_errors && use_line) possible = false;
    }

    if (possible)
        cout << "Y\n";
    else
        cout << "N\n";

    return 0;
}

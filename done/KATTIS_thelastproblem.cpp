#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string s = "";
    string p;
    while (cin >> p) {
        s += " " + p;
    }

    cout << "Thank you, " << s.substr(1) << ", and farewell!" << endl;

    return 0;
}

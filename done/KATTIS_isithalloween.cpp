#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string s;
    int d;
    cin >> s >> d;
    if ((s == "OCT" && d == 31) || (s == "DEC" && d == 25)) {
        cout << "yup\n";
    } else {
        cout << "nope\n";
    }

    return 0;
}

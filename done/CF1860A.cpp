#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        string a;
        cin >> a;

        if (a == "()")
            cout << "NO\n";
        else {
            cout << "YES\n";
            string b = string(a.size(), '(') + string(a.size(), ')');
            string c = "";
            while (c.size() < a.size() * 2) {
                c += "()";
            }
            if (b.find(a) == string::npos)
                cout << b << '\n';
            else if (c.find(a) == string::npos)
                cout << c << '\n';
        }
    }

    return 0;
}

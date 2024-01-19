// https://codeforces.com/problemset/problem/316/A1
// https://codeforces.com/problemset/problem/316/A2

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s, s2 = "";
    cin >> s;

    set<char> letras;
    for (int i = 0; i < 26; ++i) letras.insert('A' + i);

    set<char> digitos;
    for (int i = 0; i < 10; ++i) digitos.insert('0' + i);

    set<char> aparecidos;
    for (char &c : s) {
        if (letras.count(c) && aparecidos.count(c)) continue;
        if (letras.count(c)) aparecidos.insert(c);
        s2 += c;
    }

    s = s2;

    int sol = 1;
    int curr = 10;

    if (s[0] == '?') {
        sol *= 9;
    } else if (letras.count(s[0])) {
        sol *= 9;
        --curr;
    }

    string zeroes = "";
    for (int i = 1; i < (int)s.size(); ++i) {
        if (s[i] == '?') {
            zeroes += '0';
        } else if (letras.count(s[i])) {
            sol *= curr--;
        }
    }

    cout << sol << zeroes << endl;

    return 0;
}

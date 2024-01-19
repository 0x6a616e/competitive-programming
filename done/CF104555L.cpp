// https://codeforces.com/gym/104555/problem/L

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s;
    int k;

    cin >> s >> k;

    vector<priority_queue<int, vector<int>, greater<int>>> letras(k);

    for (int i = 0; i < (int)s.size(); ++i) letras[i % k].push(s[i]);

    for (int i = 0; i < (int)s.size(); ++i) {
        cout << char(letras[i % k].top());
        letras[i % k].pop();
    }
    cout << endl;

    return 0;
}

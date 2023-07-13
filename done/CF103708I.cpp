// https://codeforces.com/gym/103708/problem/I

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, c = 0;
    string num;

    cin >> num;

    N = stoi(num);

    for (int i = 0; i < num.size(); i++) {
        if (num[i] != '0' && N % (num[i] - '0') == 0) {
            c++;
        }
    }

    cout << c << '\n';

    return 0;
}

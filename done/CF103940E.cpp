// https://codeforces.com/gym/103940/problem/E

#include <bits/stdc++.h>

using namespace std;

int ceil(int a, int b) { return (a + b - 1) / b; }

int main() {
    int N, M;

    cin >> N >> M;
    cout << ceil(N, M) << endl;
}

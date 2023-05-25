// https://codeforces.com/gym/103940/problem/E

#include <bits/stdc++.h>

using namespace std;

int main()
{
        int N, M;

        cin >> N >> M;

        if (N % M != 0) {
                cout << (N / M) + 1 << '\n';
        } else {
                cout << (N / M) << '\n';
        }
}

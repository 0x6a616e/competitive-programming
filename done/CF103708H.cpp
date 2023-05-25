// https://codeforces.com/gym/103708/problem/H

#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int N;
        
        cin >> N;

        if (N % 2 != 0) {
                N--;
        }
        if (N % 4 == 0) {
                cout << N / 4 * N / 4 << '\n';
        } else {
                cout << (N / 4) * (N / 4 + 1) << '\n';
        }

        return 0;
}

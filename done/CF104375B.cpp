// https://codeforces.com/gym/104375/problem/B

#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        double N, K, L;

        cin >> N >> K >> L;

        cout << ceil(N * K / L) << '\n';

        return 0;
}

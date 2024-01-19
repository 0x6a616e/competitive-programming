// https://codeforces.com/problemset/problem/977/A

#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int k;
        long long n;

        cin >> n >> k;

        for (int i = 0; i < k; i++) {
                if (n % 10) {
                        n--;
                } else {
                        n /= 10;
                }
        }

        cout << n << '\n';
        
        return 0;
}

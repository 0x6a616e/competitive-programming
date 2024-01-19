#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    unsigned long long k, izq, der, mid;

    cin >> n >> k;

    izq = 0;
    der = ((unsigned long long)1 << n) - 1;
    --k;

    while (izq <= der) {
        mid = (izq + der) / 2;
        if (mid == k) {
            cout << n << endl;
            break;
        }
        if (mid < k) izq = mid + 1;
        if (mid > k) der = mid - 1;
        --n;
    }

    return 0;
}

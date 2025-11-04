#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    long long n;
    cin >> n;
    unsigned long long aux = n;
    vector<int> f;
    for (long long i = 2; (unsigned long long)i * i <= aux && n > 1 && f.size() < 3; ++i) {
        if (n % i != 0) continue;
        int c = 0;
        while (n % i == 0) {
            ++c;
            n /= i;
        }
        f.push_back(c);
    }
    if (n > 1) f.push_back(1);
    cout << ((!f.empty() && ((f.size() == 1 && f[0] % 2 == 1) || (f.size() == 2 && f[0] == 1 && f[1] == 1))) ? "Y" : "N") << endl; 

    return 0;
}

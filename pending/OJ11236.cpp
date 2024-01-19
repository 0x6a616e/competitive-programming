#include <bits/stdc++.h>

using namespace std;

string convert(int n) {
    string res = "00.00";
    res[4] += n % 10;
    n /= 10;
    res[3] += n % 10;
    n /= 10;
    res[1] += n % 10;
    n /= 10;
    res[0] += n % 10;
    if (res[0] == '0') res = res.substr(1);
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int a, b, c, d;

    for (a = 1; a <= 2000; ++a) {
        for (b = a; a + b <= 2000; ++b) {
            for (c = b; a + b + c <= 2000; ++c) {
                int bb = a * b * c;
                int cc = 1000000;
                if (bb == cc) continue;

                int aa = a + b + c;
                int dd = cc * aa;
                int ee = bb - cc;

                if (dd % ee) continue;

                d = dd / ee;
                if (c > d) continue;
                if (aa + d > 2000) continue;
                if (bb * d > 2000000000) continue;
                cout << convert(a) << ' ' << convert(b) << ' ' << convert(c)
                     << ' ' << convert(d) << '\n';
            }
        }
    }

    return 0;
}

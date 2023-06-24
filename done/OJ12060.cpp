#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
        while (b) {
                a %= b;
                swap(a, b);
        }
        return a;
}

struct Fraction {
        int a, b, c;
        bool sign;

        Fraction(int num, int denum) {
                sign = num < 0;
                a = abs(num) / denum;
                b = abs(num) % denum;
                c = denum;

                int mcd = gcd(b, c);
                while (mcd != 1) {
                        b /= mcd;
                        c /= mcd;
                        mcd = gcd(b, c);
                }
        }

        void print() {
                if (b) {
                        int digits_a = ( a ? log10(a) + 1 : 0);
                        int digits_b = log10(b) + 1;
                        int digits_c = log10(c) + 1;

                        int digits = digits_a + digits_c - digits_b;
                        if (sign) {
                                digits += 2;
                        }
                        cout << string(digits, ' ') << b << '\n';
                        if (sign) {
                                cout << "- ";
                        }
                        if (a) {
                                cout << a;
                        }
                        cout << string(digits_c, '-') << '\n';
                        digits = digits_a;
                        if (sign) {
                                digits += 2;
                        }
                        cout << string(digits, ' ') << c << '\n';
                } else {
                        if (sign) {
                                cout << "- ";
                        }
                        cout << a << '\n';
                }
        }
};

int main() {
        cin.tie(0);
        ios::sync_with_stdio(0);

        int n, num, c = 0;
        
        while (cin >> n && n) {
                c++;
                int acum = 0;
                for (int i = 0; i < n; i++) {
                        cin >> num;
                        acum += num;
                }
                Fraction fraction(acum, n);
                cout << "Case " << c << ":\n";
                fraction.print();
        }

        return 0;
}

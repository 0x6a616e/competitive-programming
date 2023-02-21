#include <iostream>
#include <vector>

using namespace std;

int main()
{
        int n, e;
        vector<int> A, B;
        vector <long long> p, r;

        while (cin >> n) {
                A.clear();
                A.resize(n, 0);

                B.clear();
                B.resize(n, 0);

                r.clear();
                r.resize(3, 0);

                p.clear();
                p.resize(3, 0);

                for (int i = 0; i < n; i++)
                        cin >> A[i];

                for (int i = 0; i < n; i++)
                        cin >> B[i];

                for (int i = 0; i < n; i++)
                        p[i % 3] += A[i];

                for (int i = 0; i < n; i++) {
                        e = i % 3;
                        for (int j = 0; j < 3; j++) {
                                r[e] += p[j] * B[i];
                                e = (e + 1) % 3;
                        }
                }

                cout << r[1] << ' ' << r[2] << ' ' << r[0] << '\n';
        }
        
        return 0;
}

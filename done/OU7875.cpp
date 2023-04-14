#include <iostream>

using namespace std;

int main()
{
        cin.tie(nullptr);
        ios_base::sync_with_stdio(false);
        
        int N, num, c1, c2, c2tmp;

        c1 = 0;
        c2 = 0;
        c2tmp = 0;

        cin >> N;

        for (int i = 0; i < N; i++) {
                cin >> num;

                if (num == 1) {
                        if (c2 != 0 || c2tmp != 0)
                                c1++;
                        c2 += c2tmp;
                        c2tmp = 0;
                } else if (num == 2) {
                        c2tmp++;
                }
        }

        cout << (c1 < c2 ? c1 : c2) << '\n';

        return 0;
}

#include <iostream>

using namespace std;

int main()
{
        int W, N, wi, li, acum;

        while (cin >> W) {
                acum = 0;
                cin >> N;
                for (int i = 0; i < N; i++) {
                        cin >> wi >> li;
                        acum += (wi * li);
                }
                cout << acum / W << '\n';
        }
        
        return 0;
}

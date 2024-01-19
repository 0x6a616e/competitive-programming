#include <iostream>

using namespace std;

bool isLeap(int y) {
        if (y % 400 == 0)
                return true;
        else if (y % 100 == 0)
                return false;
        else if (y % 4 == 0)
                return true;
        else
                return false;
}

int main()
{
        int T, D, M, Y, QY, E;

        cin >> T;

        for (int i = 0; i < T; i++) {
                cin >> D >> M >> Y >> QY;

                if (D == 29 && M == 2) {
                        E = 0;
                        for (int j = Y + 1; j <= QY; j++)
                                if (isLeap(j))
                                        E++;
                } else {
                        E = QY - Y;
                }

                cout << "Case " << i + 1 << ": " << E << '\n';
        }
        
        return 0;
}

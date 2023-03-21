#include <iostream>

using namespace std;

int main()
{
        cin.tie(nullptr);
        ios_base::sync_with_stdio(false);

        int N, H, W;
        char tW, tH;

        cin >> N >> H >> W;

        for (int i = 0; i < N; i++) {
                cin >> tW >> tH;
                if (tW == 'Y' || (tW == 'N' && W == 0)) {
                        cout << "Y ";
                        H--;
                        W++;
                } else {
                        cout << "N ";
                }

                if (tH == 'Y' || (tH == 'N' && H == 0)) {
                        cout << "Y\n";
                        W--;
                        H++;
                } else {
                        cout << "N\n";
                }
        }
        
        return 0;
}

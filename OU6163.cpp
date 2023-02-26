#include <iostream>

using namespace std;

int main()
{
        cin.tie(nullptr);
        ios_base::sync_with_stdio(false);
        
        unsigned short int K;
        int N, M;

        cin >> K;
        for (unsigned short int i = 0; i < K; i++) {
                cin >> N >> M;
                if (N < M)
                        cout << (N - 1) * 2 << '\n';
                else
                        cout << (M - 1) * 2 << '\n';
        }
        
        return 0;
}

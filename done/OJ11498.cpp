#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int K, N, M, X, Y;

        while (cin >> K && K != 0) {
                cin >> N >> M;
                for (int i = 0; i < K; i++) {
                        cin >> X >> Y;
                        if (X == N || Y == M) {
                                cout << "divisa\n";
                        } else {
                                if (Y > M) {
                                        if (X < N) {
                                                cout << "NO\n";
                                        } else {
                                                cout << "NE\n";
                                        }
                                } else {
                                        if (X < N) {
                                                cout << "SO\n";
                                        } else {
                                                cout << "SE\n";
                                        }
                                }
                        }
                }
        }
        
        return 0;
}

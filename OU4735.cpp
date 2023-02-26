#include <iostream>
#include <vector>

using namespace std;

vector<int> calculos(31, -1);

int solve(int N) {
        int acum = 0;
        if (calculos[N] == -1) {
                acum += 3 * solve(N - 2);
                for (int i = 2; 2 * i < N; i++) {
                        acum += 2 * solve(N - 2 * i);
                }
                calculos[N] = acum + 2;
        }
        return calculos[N];
}

int main()
{
        int N;
        calculos[2] = 3;

        while (cin >> N)
                if (N % 2 != 0)
                        cout << "0\n";
                else
                        cout << solve(N) << '\n';
        
        return 0;
}

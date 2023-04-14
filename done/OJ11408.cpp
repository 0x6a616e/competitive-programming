#include <iostream>
#include <vector>

using namespace std;

int MAX = 5000001;
vector<bool> criba(MAX, true);
vector<int> primos;
vector<int> calculos(MAX, -1);

int solve(int i) {
        int p = 0;
        int m = i;
        if (calculos[i] == -1) {
                for (p; i % primos[p] != 0; p++);
                for (m; m % primos[p] == 0; m /= primos[p]);
                calculos[i] = primos[p] + solve(m);
        }
        return calculos[i];
}

int main()
{
        for (int i = 2; i < MAX; i++)
                if (criba[i]) {
                        primos.push_back(i);
                        calculos[i] = i;
                        for (int j = 2; i * j <= MAX; j++)
                                criba[i * j] = false;
                }
        
        calculos[0] = 0;
        calculos[1] = 0;

        int a, b, c;

        while (cin >> a && a != 0) {
                cin >> b;

                c = 0;

                for (int i = a; i <= b; i++)
                        if (criba[solve(i)])
                                c++;

                cout << c << '\n';
        }
        
        return 0;
}

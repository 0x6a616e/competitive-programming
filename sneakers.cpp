#include <iostream>
#include <map>

using namespace std;

int main()
{
        int K, N, shoe, pairs;
        map<int, int> shoes;

        cin >> K;

        while (K--) {
                shoes.clear();
                pairs = 0;

                cin >> N;

                for (int i = 0; i < N; i++) {
                        cin >> shoe;
                        if (shoes[shoe]++) {
                                shoes[shoe] = 0;
                                pairs++;
                        }
                }

                if (pairs * 2 == N)
                        cout << ":)\n" << N << '\n';
                else {
                        for (map<int, int>::iterator it = shoes.begin(); it != shoes.end(); it++)
                                if (it->second == 1)
                                        cout << it->first << ' ';
                        cout << '\n' << pairs * 2 << '\n';
                }
        }
        
        return 0;
}

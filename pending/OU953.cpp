#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
        int N, M, P;
        vector<int> Ns;
        vector<int>::iterator pos;
        while (cin >> N >> M) {
                Ns.clear();
                Ns.resize(N, 0);

                for (int i = 0; i < N; i++)
                        cin >> Ns[i];
                
                for (int i = 0; i < M; i++) {
                        cin >> P;
                        pos = find(Ns.begin(), Ns.end(), P);
                        if (pos == Ns.end())
                                cout << "-1\n";
                        else
                                cout << pos - Ns.begin() << '\n';
                }
        }
        
        return 0;
}

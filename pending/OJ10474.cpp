#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
        int caso = 0, N, Q, marble, query;
        vector<int> marbles;
        vector<int>::iterator posicion;

        while (cin >> N >> Q && !(N == 0 && Q == 0)) {
                marbles.clear();
                caso++;
                cout << "CASE# " << caso << ":\n";

                for (int i = 0; i < N; i++) {
                        cin >> marble;
                        marbles.push_back(marble);
                }

                sort(marbles.begin(), marbles.end());

                for (int i = 0; i < Q; i++) {
                        cin >> query;
                        posicion = find(marbles.begin(), marbles.end(), query);
                        if (posicion == marbles.end())
                                cout << query << " not found\n";
                        else
                                cout << query << " found at " << posicion - marbles.begin() + 1 << '\n';
                }
        }
        
        return 0;
}

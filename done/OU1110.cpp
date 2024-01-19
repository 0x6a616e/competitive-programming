#include <iostream>
#include <iomanip>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<long, int>, null_type, less<pair<long, int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);
        
        int N, c;
        long score;
        double acum = 0;
        indexed_set rankings;

        cin >> N;

        c = 0;

        for (int i = 0; i < N; i++) {
                cin >> score;
                rankings.insert({ score, c });
                acum += (rankings.size() - rankings.order_of_key({ score, c }));
                c++;
        }

        cout << fixed << setprecision(2) << acum / N << '\n';
        
        return 0;
}

#include <iostream>
#include <iomanip>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main()
{
        int N, score, acum = 0;
        indexed_set rankings;

        cin >> N;

        for (int i = 0; i < N; i++) {
                cin >> score;
                rankings.insert(score);
                acum += (rankings.size() - rankings.order_of_key(score));
        }

        cout << fixed << setprecision(2) << acum / (float) rankings.size() << '\n';
        
        return 0;
}

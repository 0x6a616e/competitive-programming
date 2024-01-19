#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update
> indexed_set;

int main() {
        cin.tie(0);
        ios::sync_with_stdio(0);

        int S, B;

        while (cin >> S >> B && S && B) {
                indexed_set soldiers;
                soldiers.insert(-1);
                for (int i = 1; i <= S; ++i) {
                        soldiers.insert(i);
                }
                soldiers.insert(S + 1);
                int l, r;
                for (int _ = 0; _ < B; _++) {
                        cin >> l >> r;
                        for (int i = l; i <= r; ++i) {
                                soldiers.erase(i);
                        }
                        int il = soldiers.order_of_key(l);
                        int ir = soldiers.order_of_key(r);
                        int sl, sr;
                        sl = *soldiers.find_by_order(il - 1);
                        sr = *soldiers.find_by_order(ir);
                        if (sl == -1) {
                                cout << '*';
                        } else {
                                cout << sl;
                        }
                        cout << ' ';
                        if (sr == 0 || sr == S + 1) {
                                cout << '*';
                        } else {
                                cout << sr;
                        }
                        cout << '\n';
                }
                cout << "-\n";
        }
        
        return 0;
}

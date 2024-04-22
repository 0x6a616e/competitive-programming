#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, k = 1;
    cin >> n;

    indexed_set is;
    for (int i = 1; i <= n; ++i) is.insert(i);

    int index = k % n;
    for (int i = 0; i < n; ++i) {
        auto it = is.find_by_order(index);
        cout << *it << ' ';
        is.erase(it);
        if (is.size()) index = (index + k) % is.size();
    }
    cout << endl;

    return 0;
}

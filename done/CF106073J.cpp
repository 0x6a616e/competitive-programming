#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    set<int> ans;
    for (int i = 0; i < 10; ++i) {
        int t;
        cin >> t;
        ans.insert(t);
    }
    cout << 4 - ans.size() << endl;

    return 0;
}

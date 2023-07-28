#include <iomanip>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int c;
    string tree;

    cin >> c;

    getline(cin, tree);
    getline(cin, tree);

    while (c--) {
        map<string, int> counter;
        int global_counter = 0;
        while (getline(cin, tree) && tree != "") {
            ++global_counter;
            ++counter[tree];
        }

        for (map<string, int>::iterator it = counter.begin();
             it != counter.end(); ++it) {
            cout << it->first << ' ' << fixed << setprecision(4)
                 << (it->second * 100.0 / global_counter) << '\n';
        }

        if (c > 0) {
            cout << '\n';
        }
    }

    return 0;
}

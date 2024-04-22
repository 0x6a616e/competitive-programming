#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int f;

    while (cin >> f && f) {
        map<string, int> counter;
        int maximum = 0;
        vector<string> courses(5);

        for (int i = 0; i < f; ++i) {
            string combination = "";
            for (int j = 0; j < 5; ++j) {
                cin >> courses[j];
            }
            sort(courses.begin(), courses.end());
            for (int j = 0; j < 5; ++j) {
                combination += courses[j];
            }
            ++counter[combination];
            maximum = max(maximum, counter[combination]);
        }

        int c = 0;

        for (map<string, int>::iterator it = counter.begin();
             it != counter.end(); ++it) {
            if (it->second == maximum) {
                c += it->second;
            }
        }

        cout << c << '\n';
    }

    return 0;
}

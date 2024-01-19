#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int c;

    cin >> c;

    while (c--) {
        int n;

        cin >> n;

        map<int, int> indexes;
        int maximum = 0;
        int package_start = 1;
        int package_end = 0;
        int snowflake;

        for (int i = 0; i < n; ++i) {
            cin >> snowflake;

            ++package_end;
            if (indexes[snowflake] >= package_start) {
                package_start = indexes[snowflake] + 1;
            }
            indexes[snowflake] = package_end;

            maximum = max(maximum, (package_end - package_start + 1));
        }

        cout << maximum << '\n';
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        int n;

        cin >> n;

        vector<int> students(n);

        for (int i = 0; i < n; i++) {
                cin >> students[i];
        }

        sort(students.begin(), students.end());

        int acum = 0;
        for (int i = 0; i < n; i += 2) {
                acum += (students[i + 1] - students[i]);
        }

        cout << acum << '\n';
        
        return 0;
}

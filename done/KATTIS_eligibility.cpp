#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    while (n--) {
        string name;
        char z;
        int y1, m1, d1, y2, m2, d2, courses;
        cin >> name >> y1 >> z >> m1 >> z >> d1 >> y2 >> z >> m2 >> z >> d2 >> courses;

        int ans = 0;
        if (y1 >= 2010) {
            ans = 1;
        }
        if (y2 >= 1991) {
            ans = 1;
        }
        if (ans == 0 && courses > 40) {
            ans = -1;
        }
        if (ans == 1) {
            cout << name << " eligible\n";
        } else if (ans == -1) {
            cout << name << " ineligible\n";
        } else {
            cout << name << " coach petitions\n";
        }
    }
}

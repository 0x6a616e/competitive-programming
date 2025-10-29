#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, y;
    scanf("%i %i", &x, &y);

    if (y == 1 && x == 0) {
        printf("ALL GOOD\n");
    } else if (y == 1) {
        printf("IMPOSSIBLE\n");
    } else {
        double ans = (double)x / (1 - y);
        printf("%.6f\n", ans);
    }
    
    return 0;
}

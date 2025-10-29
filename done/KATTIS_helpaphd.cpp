#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%i", &n);

    char* l = new char[5];
    char* m = new char[5];
    char* r = new char[5];
    while (n--) {
        scanf("%[^=+]%[=+]%s", l, m, r);
        if (m[0] == '=') {
            printf("skipped\n");
        } else {
            int a = stoi(l);
            int b = stoi(r);
            printf("%i\n", a + b);
        }
    }
}

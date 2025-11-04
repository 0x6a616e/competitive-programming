#include <iostream>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    if (n % 2) --n;
    int a = n / 4;
    int b = (n + 3) / 4;
    cout << a * b << endl;

    return 0;
}

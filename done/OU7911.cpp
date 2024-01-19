#include <iostream>

using namespace std;

int main()
{
        int a, b, c, d;

        while (cin >> a >> b >> c >> d) {
                if (a == d && b == c)
                        cout << "1\n";
                else
                        cout << "0\n";
        }

        return 0;
}

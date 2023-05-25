// https://codeforces.com/gym/104252/problem/M

#include <bits/stdc++.h>

using namespace std;

int C, rotacion = 0;

string move(string bolt, char movement) {
        if (movement == 'd') {
                rotacion = (rotacion + 1) % C;
                return bolt.back() + bolt.substr(0, bolt.size() - 1);
        }
        if (movement == 'i') {
                rotacion--;
                if (rotacion < 0) {
                        rotacion += C;
                }
                return bolt.substr(1) + bolt[0];
        }
}

bool posible(string bolt, string fila, char movement) {
        
}

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        return 0;
}

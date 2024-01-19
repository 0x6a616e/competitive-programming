#include <iostream>
#include <map>

using namespace std;

int main()
{
        int n;
        string linea;
        map<string, int> contador;
        cin >> n;
        for (int i = 0; i < n; i++) {
                cin >> linea;
                contador[linea]++;
                getline(cin, linea);
        }
        for (map<string, int>::iterator it = contador.begin(); it != contador.end(); it++)
                cout << it->first << ' ' << it->second << '\n';
        
        return 0;
}

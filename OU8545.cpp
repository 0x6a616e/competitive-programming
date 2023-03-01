#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> memo(76, vector<int>(2, -1));

int solve(short int O, short int l) {
        if (memo[l][O] == -1) {
                if (O == 0)
                        memo[l][O] = solve(1, l - 2);
                else
                        memo[l][O] = solve(0, l - 2) + solve(1, l - 2);
        }
        return memo[l][O];
}

int main()
{
        short int N;
        memo[1][0] = 1;
        memo[1][1] = 2;
        memo[2][0] = 1;
        memo[2][1] = 1;

        cin >> N;

        if (N == 0 || N == 2)
                cout << "1\n";
        else if (N == 1)
                cout << "2\n";
        else
                cout << solve(0, N - 2) + solve(1, N - 2) << '\n';
        
        return 0;
}
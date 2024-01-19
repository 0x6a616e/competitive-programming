// https://codeforces.com/problemset/problem/339/A

#include <bits/stdc++.h>

using namespace std;

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        string suma;
        vector<int> nums;

        cin >> suma;

        for (int i = 0; i < suma.size(); i += 2) {
                nums.push_back(suma[i] - '0');                
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
                cout << nums[i];
                if (i < nums.size() - 1) {
                        cout << '+';
                }
        }
        cout << '\n';
}

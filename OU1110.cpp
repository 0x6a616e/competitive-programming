#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
        cin.tie(nullptr);
        ios_base::sync_with_stdio(false);
        
        int N, num, pos, acum = 0;
        vector<int>::iterator it;
        vector<int> nums;

        cin >> N;

        nums.reserve(N);
        
        for (int i = 0; i < N; ++i) {
                cin >> num;
                it = lower_bound(nums.begin(), nums.end(), num);
                pos = nums.end() - it + 1;
                nums.emplace(it, num);
                acum += pos;
        }
        cout << fixed << setprecision(2) << acum / (float) N << '\n';
        
        return 0;
}

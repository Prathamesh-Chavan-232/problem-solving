#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {

        int n = nums.size();
        int res = 0;

        for (int i = 0; i < n; ++i)
        {
            int q = nums[i];
            bool isEven;
            
            // divide by 100 till the number has 1 or 2 digits left;
            while (q >= 100)
            {
                q = q / 100;
            }
            isEven = q > 9;
            
            if (isEven)
            {
                res++;
            }
        }
        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:/Prathamesh/Programming/input.txt", "r", stdin);
    freopen("C:/Prathamesh/Programming/output.txt", "w", stdout);
#endif

    Solution s;
    vector<int> nums = {12, 345, 2, 6, 7896};
    int res = s.findNumbers(nums);
    cout << res << endl;
    return 0;
}
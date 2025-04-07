#include <bits/stdc++.h>
using namespace std;
// Solution 1
class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int sum = 0, ans = 0;
        for (int i = 0; i < accounts.size(); i++)
        {
            for (int j = 0; j < accounts[i].size(); j++)
            {
                sum += accounts[i][j];
            }
            ans = max(ans, sum);
            sum = 0;
        }
        return ans;
    }
};
// Solution 2

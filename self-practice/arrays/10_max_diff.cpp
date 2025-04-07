#include <bits/stdc++.h>
using namespace std;
class Solution1
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int max_diff = -1, diff = -1;
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (nums[j] > nums[i])
                {
                    diff = nums[j] - nums[i];
                }
                max_diff = max(max_diff, diff);
            }
        }
        return max_diff;
    }
};
class Solution2
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int n = nums.size();
        int max_diff = -1, diff;
        int min = nums[0];
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] <= min)
            {
                min = nums[i];
            }
            else
            {
                diff = nums[i] - min;
                max_diff = max(max_diff, diff);
            }
        }
        return max_diff;
    }
};
class Solution3
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int n = nums.size();
        int max_diff = -1, diff;
        int min_ = nums[0];
        for (int i = 1; i < n; ++i)
        {

            min_ = min(min_, nums[i]);
            diff = nums[i] - min_;
            max_diff = max(max_diff, diff);
        }
        return max_diff;
    }
};
int main()
{
    /*code*/
    return 0;
}
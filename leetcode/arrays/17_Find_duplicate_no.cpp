#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int i = 0, res = -1;
        while (i < nums.size())
        {
            if (nums[i] != i + 1)
            {
                int correct = nums[i] - 1;
                if (nums[i] != nums[correct])
                {
                    swap(nums[i], nums[correct]);
                }
                else
                    return nums[i];
            }
            else
            {
                i++;
            }
        }
    }
};
int main()
{

    return 0;
}
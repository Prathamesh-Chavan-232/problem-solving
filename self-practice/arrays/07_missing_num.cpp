// Leetcode - easy - amazon interview question
// Solution 1 - cyclic sort

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int i = 0;
        while (i < nums.size())
        {
            if ((nums[i] != i) && (nums[i] < nums.size()))
            {
                swap(nums[i], nums[nums[i]]);
            }
            else
            {
                i++;
            }
        }
        int i = 0;
        for (; i < nums.size(); i++)
        {
            if (nums[i] != i)
            {
                return i;
            }
        }
        return i;
    }
};
// Solution 2 - Using AP
class Solution2
{
public:
    int missingNumber(vector<int> &nums)
    {
        int sum1 = 0, sum2 = (nums.size() * (nums.size() + 1)) / 2;
        for (int i = 0; i < nums.size(); i++)
        {
            sum1 += nums[i];
        }
        return (sum2 - sum1);
    }
};
// Solution 3 - bit manipulation
class Solution3
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int x1 = 0;
        int x2 = 0;
        for (int i = 0; i < n; i++)
        {
            x1 = x1 ^ nums[i]; // let say array is 3,0,1 then x1 will store  3^0^1
            x2 = x2 ^ (i + 1); // here x2 will store 1^2^3
        }
        return x1 ^ x2; //  a^a=0 ,so the number present both in x1 and x2 will cancel out(become zero ) and the element which is not present in x1 . i.e 2 will be returned by the function.
    }
};
int main()
{
    // debugging for solutions
    Solution s;
    vector<int> arr = {3, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = s.missingNumber(arr);
    printf("%d\n", res);
    return 0;
}

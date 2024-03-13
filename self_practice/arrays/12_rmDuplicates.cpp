#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void printArr(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
    void deleteAtIndex(vector<int> &arr, int index, int count, int n)
    {

        for (int i = index; i < n - 1; ++i)
        {
            arr[i - count] = arr[i];
        }
    }
    int removeDuplicates(vector<int> &nums)
    {

        int n = nums.size();
        int i = 0, count = 0;
        while (i < n - 1)
        {
            if (nums[i] == nums[i + 1])
            {
                i++;
                count++;
            }
            else
            {
                cout << "before delete ";
                printArr(nums);
                deleteAtIndex(nums, i + 1, count, n);
                cout << "after delete i: ";
                printArr(nums);
                i = (i + 1) - count;
                cout << "count: " << count << endl;
                n -= count;
                count = 0;
            }
        }
        return n;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    s.removeDuplicates(nums);
    for (int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << " ";
    }
    return 0;
}
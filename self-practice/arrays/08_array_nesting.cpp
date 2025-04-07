#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
    int isEqual(vector<int> &temp, int x)
    {
        for (int i = 0; i < temp.size(); i++)
        {
            if (x == temp[i])
            {
                return 1;
            }
        }
        return 0;
    }
    int arrayNesting(vector<int> &nums)
    {
        vector<int> temp;
        int k = 0;
        while (k < nums.size())
        {
            temp.push_back(nums[k]);
            printf("Temp is : ");
            for (int i = 0; i < temp.size(); i++)
            {
                cout << temp[i] << " ";
            }
            printf("\n");
            k = nums[k];
            cout << "k is " << k << "\n\n";
            if (isEqual(temp, nums[k]) == 1)
            {
                break;
            }
            cout << "Temp size : " << temp.size() << "\n";
        }
        return temp.size();
    }
};
int main()
{
    vector<int> nums = {5, 4, 0, 3, 1, 6, 2};
    Solution s;
    int x = s.arrayNesting(nums);
    cout << x;
}

// gfg Question of the day 29/11/21 - Medium
// Link - https://practice.geeksforgeeks.org/problems/fab3dbbdce746976ba35c7b9b24afde40eae5a04/1

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
    vector<int> help_classmate(vector<int> arr, int n)
    {
        vector<int> res(n);
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (arr[i] > arr[j])
                {
                    res[i] = arr[j];
                    break;
                }
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (res[i] == 0)
            {
                res[i] = -1;
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> arr = {3, 8, 5, 2, 25};
    int n = arr.size();
    vector<int> res = s.help_classmate(arr, n);
    for (auto &value : res)
    {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}
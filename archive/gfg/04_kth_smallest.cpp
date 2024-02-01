// GFG question for love babbar sheet - Easy
// Link - https://practice.geeksforgeeks.org/problems/kth-smallest-number-in-multiplication-table/1

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthSmallest(vector<int> arr, int l, int h, int k)
    {
        set<int> s;
        for (int i = 0; i < h + 1; ++i)
        {
            s.insert(arr[i]);
        }
        auto it = s.begin();
        advance(it, k - 1);
        return (*it);
    }
};
int main()
{

    Solution s;
    vector<int> arr = {7, 10, 4, 3, 15, 20};
    int k = 3;
    int l = 0;
    int h = arr.size() - 1;
    int kth_min = s.kthSmallest(arr, l, h, k);
    cout << kth_min << endl;
    return 0;
}
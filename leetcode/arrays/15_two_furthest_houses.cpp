// Q) Two Furthest houses - Leetcode - Easy
// Similar to Max diff
// Link - https://leetcode.com/problems/two-furthest-houses-with-different-colors/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxDistance(vector<int> &colors)
    {
        int n = colors.size();
        int diff = 0, max_diff = 0;
        int i = 0, j = n - 1;
        while (colors[j] == colors[0])
        {
            --j;
        }
        while (colors[i] == colors[n - 1])
        {
            ++i;
        }
        max_diff = max(j - 0, n - 1 - i);
        return max_diff;
    }
};
int main()
{
    /*code*/
    return 0;
}
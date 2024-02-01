#include <bits/stdc++.h>
using namespace std;

#define fo(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
typedef vector<int> vi;

/*
    Link - https://www.geeksforgeeks.org/maximum-absolute-difference-value-index-sums/
    Problem - maximum absolute difference in an array
    Difficulty - Easy
    contest - no
    Status - Solved by reading article
    Date - 11/4/22

Approach -

*/

class Solution
{
public:
    int maxDistance(vi arr)
    {
        int n = arr.size();
        int max1 = INT_MAX, max2 = INT_MAX;
        int min1 = INT_MIN, min2 = INT_MIN;
        fo(i, n)
        {
            max1 = max(max1, arr[i] + i);
            min1 = min(min1, arr[i] + i);

            max2 = max(max2, arr[i] - i);
            min2 = min(min2, arr[i] - i);
        }
        int res = max(max1 - min1, max2 - min2);
        return res;
    }
};

/*
    Link - https://www.geeksforgeeks.org/maximum-absolute-difference-value-index-sums/
    Problem - Maximum absolute difference in an array
    Difficulty - Easy
    contest - no
    Status - solved after reading article
    Date - 11/4/22

Approach -

An efficient solution in O(n) time complexity can be worked out
using the properties of absolute values.

f(i, j) = |A[i] – A[j]| + |i – j| can be written in 4 ways

Case 1: f(i, j) = (A[i] + i) - (A[j] + j)     { i > j, A[i] > A[i] }
Case 2:f(i, j) = -(A[i] + i) + (A[j] + j)    { i < j, A[i] < A[i] }

Case 3: f(i, j) = (A[i] - i) - (A[j] - j)    { i > j, A[i] < A[i] }
Case 4: f(i, j) = -(A[i] - i) + (A[j] - j)   { i < j, A[i] > A[i] }

case 1 & 2 and case 3 & 4 are equivalent

1. Calculate the value of A[i] + i and A[i] – i
   for every element of the array while traversing through the array.

2. Then for the two equivalent cases, we find the maximum possible value.
   For that, we have to store minimum and maximum values of expressions A[i] + i and A[i] – i for all i.

3. Therefore max1 = max(A[i] + i) and max2 = max(A[i] - i)
3. Therefore min1 = min(A[i] + i) and min2 = min(A[i] - i)
    Answer = max(max1 - min1, max2 - min2)
*/

void solve()
{
    Solution s;
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:/Prathamesh/Programming/input.txt", "r", stdin);
    freopen("C:/Prathamesh/Programming/output.txt", "w", stdout);
    freopen("C:/Prathamesh/Programming/err.txt", "w", stderr);
#endif
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        solve();
    }
    return 0;
}
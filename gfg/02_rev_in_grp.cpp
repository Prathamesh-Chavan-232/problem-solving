#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //Function to reverse every sub-array group of size k.
    void reverseInGroups(vector<long long> &arr, int n, int k)
    {
        int i = 0;
        int start = 0;
        int end = k - 1;
        while (i < 2)
        {
            while (start < end)
            {
                int temp = arr[start];
                arr[start] = arr[end];
                arr[end] = temp;
                ++start;
                --end;
            }
            start = k;
            end = n - 1;
            ++i;
        }
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<long long> arr;
        for (int i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            arr.push_back(x);
        }
        Solution s;
        s.reverseInGroups(arr, n, k);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
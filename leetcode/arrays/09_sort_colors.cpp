#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int a[300];
    void sortColors(vector<int> &a)
    {
        int zeros = 0, ones = 0, twos = 0;
        for (int i = 0; i < a.size(); ++i)
        {
            if (a[i] == 0)
            {
                ++zeros;
            }
            else if (a[i] == 1)
            {
                ++ones;
            }
            else
            {
                ++twos;
            }
        }
        int ones_start = zeros + ones;
        int twos_start = zeros + ones + twos;
        for (int i = 0; i < zeros; ++i)
        {
            a[i] = 0;
        }
        for (int i = zeros; i < ones_start; ++i)
        {
            a[i] = 1;
        }
        for (int i = ones_start; i < twos_start; ++i)
        {
            a[i] = 2;
        }
    }
    void dnf_alg(vector<int> &a)
    {
        int n = a.size();
        int low = 0, mid = 0, high = n - 1;
        while (mid <= high)
        {
            if (a[mid] == 0)
            {
                swap(a[mid++], a[low++]);
            }
            if (a[mid] == 1)
            {
                mid++;
            }

            if (a[mid] == 2)
            {
                swap(a[mid], a[high--]);
            }
        }
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    Solution s;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    s.sortColors(a);
    for (auto &value : a)
    {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}
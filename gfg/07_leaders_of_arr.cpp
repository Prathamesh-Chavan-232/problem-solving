#include <bits/stdc++.h>
using namespace std;

void brute(int arr[], int n)
{
    int flag = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[i] > arr[j])
            {
                flag = 1;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            cout << arr[i] << " ";
        }
    }
}

void soln2(int arr[], int n)
{
    int max_ = arr[n - 1];
    vector<int> res;
    res.push_back(max_);
    for (int i = n - 1; i >= 0; --i)
    {
        if (arr[i] > max_)
        {
            max_ = arr[i];
            res.push_back(max_);
        }
    }
    int res_size = res.size();
    for (int i = res_size - 1; i >= 0; --i)
    {
        cout << res[i] << " ";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:/Prathamesh/Programming/input.txt", "r", stdin);   // input
    freopen("C:/Prathamesh/Programming/output.txt", "w", stdout); // output
#endif

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    
    // brute(arr, n); // Time complexity : O(n^2)
    soln2(arr, n); // Time complexity : O(n)
    return 0;
}
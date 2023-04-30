#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void rev_arr(int &arr[], int start, int end)
{
    while (start < end)
    {
        swap(arr[start++], arr[end--])
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        rev_arr(arr, 0, n - 1);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
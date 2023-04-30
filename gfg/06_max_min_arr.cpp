/*
    Calculate the maximum and minimum element in an array with least number of comparisons
*/

#include <bits/stdc++.h>
using namespace std;
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
    int i, min_, max_;

    // If array has even number of elements
    // then initialize the first two elements
    // as minimum and maximum
    if (n % 2 == 0)
    {

        max_ = max(arr[0], arr[1]);
        min_ = min(arr[0], arr[1]);
        // Set the starting index for loop
        i = 2;
    }

    // If array has odd number of elements
    // then initialize the first element as
    // minimum and maximum
    else
    {
        min_ = arr[0];
        max_ = arr[0];
        // Set the starting index for loop
        i = 1;
    }

    // In the while loop, pick elements in
    // pair and compare the pair with max
    // and min so far
    while (i < n - 1)
    {
        if (arr[i] > arr[i + 1])
        {
            if (arr[i] > max_)
                max_ = arr[i];

            if (arr[i + 1] < min_)
                min_ = arr[i + 1];
        }
        else
        {
            if (arr[i + 1] > max_)
                max_ = arr[i + 1];

            if (arr[i] < min_)
                min_ = arr[i];
        }

        // Increment the index by 2 as
        // two elements are processed in loop
        i += 2;
    }
    return 0;
}
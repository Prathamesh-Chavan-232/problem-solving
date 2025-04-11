#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{

    /* Arrays */

    // int n;
    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; ++i)
    // {
    //     cin >> arr[i];
    // }
    // sort(arr, arr + n);
    // int *ptr = lower_bound(arr, arr + n);
    // if (ptr == arr + n)
    // {
    //     cout << "Not found!";
    // }
    // else
    // {
    //     cout << (*ptr) << "\n";
    // }

    /* Vectors */

    // int n;
    // cin >> n;
    // vector<int> m(n);
    // for (int i = 0; i < n; ++i)
    // {
    //     cin >> m[i];
    // }
    // sort(m.begin(), m.end());
    // auto it = upper_bound(m.begin(), m.end(), 4);
    // if (it == m.end())
    // {
    //     cout << "Not found!";
    // }
    // else
    // {
    //     cout << (*it) << "\n";
    // }

    /* Maps or sets */

    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; ++i)
    {
        // int x;
        // cin >> x;
        s.insert(rand());
        auto it = s.upper_bound(rand());
        if (it == s.end())
        {
            cout << "Not found!\n";
        }
        else
        {
            cout << (*it) << "\n";
        }
    }
    return 0;
}
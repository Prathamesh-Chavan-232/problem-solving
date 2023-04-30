// Range based loops and auto keyword
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
    
    // vector<int>::iterator it;
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << (*it) << " ";
    }
    cout << "\n";

    for (int value : v)
    {
        cout << value << " ";
    }
    cout << "\n";

    for (int value : v)
    {
        value++;
        // No change in original vector since elements are passed by value
    }
    for (int &value : v)
    {
        value++;
    }

    auto a = 1.0;
    cout << a << "\n";

    vector<pair<int, int>> v_p = {{1, 2}, {3, 4}};
    for (auto &value : v_p)
    {
        cout << value->first << " " << value->second << "\n";
    }
    return 0;
}
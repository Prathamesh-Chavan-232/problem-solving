#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool should_i_swap(pair<int, int> a, pair<int, int> b) // comparator function
{
    if (a.first != b.first)
    {
        return a.first > b.first ? true : false;
    }
    else
    {
        return a.second < b.second ? true : false;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        v.push_back({temp1, temp2});
    }
    
    cout << endl;
    for (int i = 0; i < n - 1; ++i)
    {
        int flag = 0;
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (should_i_swap(v[j], v[j + 1]))
            {
                swap(v[j], v[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }
    return 0;
}
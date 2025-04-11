#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // we saw that we can do indexing in vectors just like arrays
    // but other containers dont have indexes or aren't continuous
    // for that we use iterators to traverse the containers

    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
    vector<int>::iterator it = v.begin();
    for (it = v.begin; it != v.end(); it++)
    {
        cout << (*it);
    }
    vector<pair<int><int>> v_p = {{1, 2}, {3, 4}, {4, 5}};
    vector<int><int>::iterator it = v_p.begin();
    for (it = v_p.begin(); it != v_p.end(); it++)
    {
        cout << it->first << " " << it->second << "\n";
    }

    // it++ -> moves to next iterator
    // it + 1 -> moves to next location
    // therefore always use it++
    return 0;
}
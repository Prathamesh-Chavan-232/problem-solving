#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
    {
        // return a.first > b.first ? false : true;
        // if we want to swap then we need to return false
        return a.first < b.first;
    }
    else
    {
        return a.second > b.second;
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
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }
    return 0;
}
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // map<pair<int, int>, int> m;
    // pair<int, int> p1, p2;
    // p1 = {1, 2};
    // p2 = {2, 3};
    // cout << (p1 < p2);
    map<pair<string, string>, vector<int>> m1;
    int n;
    cin >> n;
    while (n--)
    {
        string fn, ln;
        int ct;
        cin >> fn >> ln >> ct;
        while (ct--)
        {
            int x;
            cin >> x;
            m1[{fn, ln}].push_back(x);
        }
    }
    for (auto &pr : m1)
    {
        auto &full_name = pr.first;
        auto &list = pr.second;
        cout << full_name.first << " " << full_name.second << " -> ";
        for (auto &value : list)
        {
            cout << value << " ";
        }
        cout << endl;;
    }
    return 0;
}
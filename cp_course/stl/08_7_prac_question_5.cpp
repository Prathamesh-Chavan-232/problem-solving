//  Hackerearth basic question
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        set<string> s;
        while (n--)
        {
            string name;
            cin >> name;
            s.insert(name);
        }
        for (auto &value : s)
        {
            cout << value << endl;
        }
    }
    return 0;
}
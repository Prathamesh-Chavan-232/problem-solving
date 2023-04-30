/*
Given N strings print unique strings in sorted order.
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    set<string> s;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        s.insert(str);
    }
    printf("Strings in sorted order : \n");
    for (auto &value : s)
    {
        cout << value << endl;
    }
    return 0;
}
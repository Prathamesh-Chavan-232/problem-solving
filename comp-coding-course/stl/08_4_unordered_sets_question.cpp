/*
Given N strings and Q queries.
In each query you are given a string
print yes if the string is present and no if it is not.
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    unordered_set<string> s;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        s.insert(str);
    }
    int q;
    cin >> q;
    while (q--)
    {
        string str;
        cin >> str;
        if (s.find(str) == s.end())
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
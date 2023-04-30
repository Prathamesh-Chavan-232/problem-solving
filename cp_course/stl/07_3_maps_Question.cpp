/*
Given n strings, print the strings in lexiographical order with their frequencies.
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<string, int> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
    //  m[s] = m[s] + 1;
        m[s]++; 
        // 1st m[s] will be 0 then we add 1 coz we added the string once
        // since all keys are unique when the same string is inserted again 
        // m[s] will increase by 1 since it will increment the same value
    }
    for(auto &pr : m)
    {
        cout << pr.first << " " << pr.second << endl;
    }
    return 0;
}
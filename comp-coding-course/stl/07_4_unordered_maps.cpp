#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void print_map(unordered_map<int, string> &m)
{
    cout << "Size = " << m.size() << endl;
    for (auto &pr : m)
    {
        cout << pr.first << " " << pr.second << endl;
    }
}
int main()
{ 
    // Stores key value pairs in random order.     
    // 1. inbuilt implementation - uses hash instead of trees
    // 2. Time complexity - O(1) for access and insert
    // 3. Valid keys datatype - only basic inbuilt datatype
    unordered_map<int,string> m;
    m[1] = "abc";  // O(1)
    m[34] = "xyz";
    m[7] = "def";
    print_map(m);
    return 0;
}
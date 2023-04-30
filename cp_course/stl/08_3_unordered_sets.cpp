#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void print_set(unordered_set<string> &s)
{
    for (string value : s)
    {
        cout << value << endl;
    }
}
int main()
{
    unordered_set<string> s;
    // Doesnt sort the elements - stores in random order
    // inbuilt implementation - hash tables
    // Time complexity - insertion - O(1)
    // Cant use data types whose built in hash functions arent defined
    // Stores unique values
    s.insert("abc");
    s.insert("wtf");
    s.insert("qwerty");
    s.insert("lol");
    s.insert("lmao");

    auto it = s.find("xyz");
    if (it != s.end())
    {
        cout << (*it) << endl;
    }
    if (it != s.end())
    {
        s.erase(it);
    }
    s.erase("abc");
    print_set(s);
    return 0;
}
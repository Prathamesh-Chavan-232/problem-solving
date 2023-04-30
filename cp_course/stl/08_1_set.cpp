#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void print_set(set<string> &s)
{
    for (string value : s)
    {
        cout << value << endl;
    }
}
int main()
{
    set<string> s;
    // Time complexity - insertion - O(log(n))
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
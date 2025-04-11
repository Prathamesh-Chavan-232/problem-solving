#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void print_set(multiset<string> &s)
{
    for (string value : s)
    {
        cout << value << endl;
    }
}
int main()
{
    multiset<string> s;
    // Can insert duplicates
    s.insert("abc");//O(log(n))
    s.insert("abc");//O(log(n))
    s.insert("xyz");
    s.insert("wtf");//O(log(n))
    s.insert("gjh");
    s.insert("lol");
    auto it = s.find("abc");
    if (it != s.end())
    {
        s.erase(it); 
        // if u remove using iterator only the value the iterator points to will be removed
    }
    s.erase("abc");
    // If u erase using value then all the value entries that match will be deleted
    // Internally this also looks for the iterator 
    print_set(s);
    return 0;
}
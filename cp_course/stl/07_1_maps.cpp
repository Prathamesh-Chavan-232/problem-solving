#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void print_map(map<int, string> &m)
{
    cout << "Size : " << m.size() << endl;
    for (auto &pr : m)
    {
        cout << pr.first << " " << pr.second << endl;
    }
}
int main()
{
    // Inbuilt implementation - Red - black trees
    // Time complexity - Insertion and random access - O(logn)
    map<int, string> m;
    m[1] = "abc"; // O(log(n))
    m[5] = "xyz";
    m[3] = "uWu";
    m.insert({4, "lol"}); // O(log(n))
    m[6];                 // O(log(n))
    // is value is not specified -> string / vector : empty string/vector
    //                              int / flaot : 0

    m[5] = "cde";
    auto it = m.find(6); // O(log(n))

    if (it == m.end())
    {
        cout << "Value not found" << endl;
    }
    else
    {
        cout << "Element found : " << it->first << " " << it->second << endl;
    }
    if (it != m.end())
    {
        m.erase(it); // O(log(n))
        // if we pass the iterator in find func 
        // it will only delete that 1 element
        // whereas if we pass a value 
        // all the elements with tht value / key will be deleted
    }

    print_map(m);
    m.clear();
    print_map(m);
    return 0;
}
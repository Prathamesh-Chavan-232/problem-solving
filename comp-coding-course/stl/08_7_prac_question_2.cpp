/*
    Hacker rank question - sets basic
    Link - https://www.hackerrank.com/challenges/cpp-sets/problem
    Time complexity - O(q*log(n))
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q, ch, x;
    set<int> s;
    set<int>::iterator it;
    cin >> q;
    while (q--)
    {
        cin >> ch >> x;
        switch (ch)
        {
        case 1:
            s.insert(x);
            break;
        case 2:
            it = s.find(x);
            if (it != s.end())
            {
                s.erase(it);
            }
            break;
        case 3:
            if (s.find(x) != s.end())
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
            break;
        default:
            break;
        }
    }
    return 0;
}

/*
    Hackerearth question - Monk and his friends
    Link - https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/monk-and-his-friends/
    Soln 1 - unoredered maps (uneccessary)
    Soln 2 - unoredered sets
    Time complexity - O(log(n))
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class soln
{
public:
    void soln_1()
    {
        int n, m;
        unordered_map<long long, int> candy_map;
        cin >> n >> m;
        for (int i = 0; i < n + m; ++i)
        {
            long long x;
            cin >> x;
            candy_map[x]++;
            if (i >= n)
            {
                if (candy_map[x] > 1)
                {
                    cout << "YES\n";
                }
                else
                {
                    cout << "NO\n";
                }
            }
        }
    }
    void soln_2()
    {
        int n, m;
        unordered_set<long long> candy_set;
        cin >> n >> m;
        for (int i = 0; i < (n + m); ++i)
        {
            long long x;
            cin >> x;
            if (i < n)
            {
                candy_set.insert(x);
            }
            else
            {
                auto it = candy_set.find(x);
                if (it != candy_set.end())
                {
                    cout << "YES\n";
                }
                else
                {
                    cout << "NO\n";
                    candy_set.insert(x);
                }
            }
        }
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        soln s;
        s.soln_1();
        // s.soln_2();
    }
    return 0;
}
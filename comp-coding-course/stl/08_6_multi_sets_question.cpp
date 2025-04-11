/*  Hacker earth question - monk and the magical candy
    Link - https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-the-magical-candy-bags/
    Soln 1 - using STL multi sets
    Time complexity - O(n*log(n))
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, k, a = 5; // n - number of candy bags , k - minutes
    long long res = 0;
    multiset<long long> bags;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 0; i < n; ++i)
        {
            long long candy;
            cin >> candy;
            bags.insert(candy);
        }
        for (int i = 0; i < k; ++i)
        {
            auto last_it = (--bags.end());
            long long candy_ct = *last_it;
            res += candy_ct;
            bags.erase(last_it);
            bags.insert(candy_ct / 2);
        }
        cout << res << endl;
    }
    return 0;
}
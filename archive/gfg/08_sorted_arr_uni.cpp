#include <bits/stdc++.h>
using namespace std;

// Shortening syntax
#define fo(i, n) for (int i = 0; i < n; ++i)
#define ll long long
#define pb push_back
typedef vector<int> vi;

/*
    Link -
    Problem - Union of 2 sorted arrays
    Difficulty - easy
    contest - no
    Status - Solved with simple method
    Date - 7/4/22

Approach -

*/

class Solution
{
public:
    // Function to solve
    vi doUnion(vi a, int n, vi b, int m)
    {
        vi uni;
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (a[i] < b[j])
            {
                uni.pb(a[i++]); // add a[i], incre i
            }
            else if (a[i] == b[j])
            {
                uni.pb(a[i++]); // add a[i]
                j++;            // incrementing j as well as i
            }
            else
            {
                uni.pb(b[j++]); // add b[j], incre j
            }
        }
        return uni;
    }
};

void solve()
{
    Solution s;
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    vi a(n), b(m);
    fo(i, n) scanf("%d", &a[i]);
    fo(j, m) scanf("%d", &b[j]);
    // debvec(a);
    // debvec(b);
    vi uni = s.doUnion(a, n, b, m);
    // debvec(uni);
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:/Prathamesh/Programming/input.txt", "r", stdin);
    freopen("C:/Prathamesh/Programming/output.txt", "w", stdout);
    freopen("C:/Prathamesh/Programming/err.txt", "w", stderr);
#endif
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// Shortening syntax
#define fo(i, n) for (int i = 0; i < n; ++i)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? ++i : --i)
#define ll long long
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)

// Debugging tools
#ifndef ONLINE_JUDGE
#define debug(...) logger(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#endif

#ifndef ONLINE_JUDGE
#define debcon(x)        \
    cerr << #x << " = "; \
    _print(x);           \
    cerr << "\n";
#else
#define debcon(x)
#endif

// Function definitions
template <typename... Args>
void logger(string varname, Args &&...values) // logger for varadiac debugging print statements
{

    cerr << varname << " = ";
    string delim = "";
    (..., (cerr << delim << values, delim = ", "));
    cerr << "\n";
}

template <typename T>
void _print(T const &c) // print any STL container
{
    cerr << "{";
    tr(it, c) cerr << *it << ", ";
    cerr << "}";
}

// constants
const int mod = 1'000'000'007;
const int N = 1e7, M = N;
const double PI = 3.1415926535897932384626;

/*
    Link - https://leetcode.com/problems/jump-game/
    Problem - Jump game
    Difficulty - medium
    contest - no
    Status - Came up with incorrect approach, solved after viewing approach
    Date - 9/4/22

Approach -
    we start from the back of the array
    keep track of a variable last
    last determines the last index from which we can reach the end
    so we start at i = arr[n - 2], last = n - 1 
    we can reach the last element if arr[i] + i >= last 
    if we can reach last from i, last = i
    we check this for every element from n - 2 to 0
    at the end last should be 0 if we can reach the end
*/

class Solution
{
public:
    bool canJump(vector<int> &arr)
    {
        int n = arr.size();
        int last = n - 1;
        Fo(i, last, -1)
        {
            if(i + arr[i] >= last)
            {
                last = i;
            }
        }
        return last == 0;
    }
};

void solve()
{
    Solution s;
    int n;
    scanf("%d", &n);
    vi arr(n);
    fo(i, n) scanf("%d", &arr[i]);
    bool res = s.canJump(arr);
    printf("%d\n", res);
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
    scanf("%d", &t);
    while (t--)
    {
        solve();
    }
    return 0;
}

/* My approach -
 (not accpeted)
    5 9 3 2 1 0 2 3 3 1 0 0
    start at the first index, i = 0, value = 5 means we can go 5 steps at max.
    from the next 5 elements select the maximum value
    and go there to have maximum steps for next jump
    keep doing this until we reach the end.

 Counter test case - 4 2 0 0 1 1 4 4 4 0 4 0

    Here, i = 0 & value = 4, in the next 4 elements max_ = 2
    But from 2 we can't go anywhere
    Handling this edge case will complicate the approach too much.
    Think simple next time
*/
bool canJump(vector<int> &arr)
{

    int jumpLen = arr[0];
    int n = arr.size();

    if (n == 1)
    {
        return true;
    }
    else if (jumpLen == 0)
    {
        return false;
    }

    int i = 0, max_;
    while (1)
    {
        max_ = i + 1;
        int j = max_ + 1;
        int pos = i + jumpLen;

        debug(i, pos);
        while (j <= pos)
        {

            if (pos >= n - 1)
            {
                debug(pos);
                return true;
            }
            if (arr[max_] <= arr[j])
            {

                debug(max_, j);
                max_ = j;
                debug(max_, j);
            }
            j++;
            // debug(arr[max_], j);
        }

        jumpLen = arr[max_];
        i = max_;
        debug(arr[max_], max_);
        if (i == n - 1)
            return true;

        if (jumpLen == 0)
            return false;
    }
}

#include <bits/stdc++.h>
using namespace std;

// Shortening syntax
#define ll long long
#define fo(i, n) for (ll i = 0; i < n; ++i)
#define Fo(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? ++i : --i)
#define foreach(it, a) for (auto it = a.begin(); it != a.end(); it++)

// Shortenting stl function calls
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

// Typdefs for containers
typedef vector<int> vi;
typedef vector<ll> vl;

// Container input tools
void inVec(vector<int> &v)
{
    string s;
    getline(cin, s);
    int num = 0, sign = 1;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '[' || s[i] == ']')
            continue;
        if (s[i] == '-')
            sign = -1;
        else if (s[i] == ',' || s[i] == ' ')
            v.push_back(num), num = 0;
        else
        {
            num = num * 10 + (s[i] - '0');
            num *= sign;
            sign = 1;
        }
    }
    v.push_back(num);
}

// Varidiac Variable debugger
#ifndef ONLINE_JUDGE
#define debug(...) logger(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#endif
template <typename... Args>
void logger(string varname, Args &&...values) // logger for varadiac debugging print statements
{

    cerr << varname << " =";
    string delim = " ";
    (..., (cerr << delim << values, delim = ", "));
    cerr << "\n";
}

// debugger for STL vector / set (of any type)
#ifndef ONLINE_JUDGE
#define debcon(x)        \
    cerr << #x << " = "; \
    _print(x);           \
    cerr << "\n";
#else
#define debcon(x)
#endif
template <typename T>
void _print(T const &c)
{
    cerr << "{ ";
    foreach (it, c)
    {
        it != --c.end() ? cerr << *it << ", " : cerr << *it;
    }
    cerr << "}";
}

/*
    Link -
    Problem -
    Difficulty -
    topic -
    Status -
    Date -
*/
/*  Approach -
        Approach 1 - T.C - O(m + n), S.C - O(n + m), Use a third array
        Approach 2 - Merging algorithm of merge sort
        Approach 3 - T.C - O(n), S.C - O(1)
            1) Initially take the gap as (m+n)/2;
            2) Take as a pt1 = 0 and pt2 = gap.
            3) Run a loop while pt2 < m + n and whenever nums1[pt1] > nums1[pt2], swap those.
            4) After completion of the loop reduce the gap as gap = ceil(gap/2).
            5) Repeat the process until gap is 1,
               if gap is 1 dont do gap = ceil(gap/2) (it will always be 1) Instead exit the loop.

*/

// classes & functions
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        for (int i = m; i < n + m; i++)
        {
            nums1[i] = nums2[i - m];
        }
        debcon(nums1);
        int gap = ceil((m + n) / 2.0);
        int i = 0, j = i + gap;
        while (gap)
        {
            debug(gap);
            i = 0;
            j = i + gap;
            while (j < (m + n))
            {
                if (nums1[i] > nums1[j])
                {
                    debug(i, j, nums1[i], nums1[j]);
                    swap(nums1[i], nums1[j]);
                }
                i++;
                j++;
            }
            if (gap == 1)
                gap = 0;
            else
                gap = ceil(gap / 2.0);
        }
    }
};

void code()
{
    Solution s;
    Add arr[i] to the map int res; // store return value
    // cout << res << endl;
}

int main()
{
    // Start time
    auto start = chrono::steady_clock::now();

    // fast io
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

// Input, Output & error messages inside text files
#ifndef ONLINE_JUDGE
    freopen("/home/falcon_codes/prathamesh/programming/input.txt", "r", stdin);
    freopen("/home/falcon_codes/prathamesh/programming/output.txt", "w", stdout);
    freopen("/home/falcon_codes/prathamesh/programming/err.txt", "w", stderr);
#endif

    int t = 1;
    // cin >> t;
    while (t--)
    {
        code();
    }

// Calculating Runtime
#ifndef ONLINE_JUDGE
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "[Finished in " << setprecision(3) << chrono::duration<double, milli>(diff).count() << " ms]\n";
#endif
    return 0;
}
// store return value
// cout << res << endl;
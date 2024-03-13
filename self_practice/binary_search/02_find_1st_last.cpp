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

/**
 * @brief -
 *  To find first pos -
 *          Binary search but keep high in the search space. (so that even if we find target, we still check behind it)
 *
 *  To find last pos -
 *          BInary search but keep low in the search space. (so that even when we find target, we still check above it)
 */

// classes & functions
class Solution
{
public:
    int lb(vector<int> &nums, int target)
    {
        int res = -1;
        int lo = 0, hi = nums.size() - 1;
        while (hi - lo > 1)
        {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }
        debug(lo, hi);

        if (nums[hi] == target)
        {
            res = hi;
        }
        if (nums[lo] == target)
        {
            res = lo;
        }
        return res;
    }
    int ub(vector<int> &nums, int target)
    {
        int res = -1;
        int lo = 0, hi = nums.size() - 1;
        while (hi - lo > 1)
        {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] <= target)
            {
                lo = mid;
            }
            else
            {
                hi = mid - 1;
            }
        }
        debug(lo, hi);
        if (nums[lo] == target)
        {
            res = lo;
        }
        if (nums[hi] == target)
        {
            res = hi;
        }
        return res;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vi ans;
        if (nums.size() == 0)
        {
            ans.pb(-1);
            ans.pb(-1);
            return ans;
        }
        int firstPos = lb(nums, target);
        int lastPos = ub(nums, target);
        ans.pb(firstPos);
        ans.pb(lastPos);
        debcon(ans);
        return ans;
    }
};
void code()
{
    Solution s;
    vi arr;
    inVec(arr);
    int target;
    cin >> target;
    s.searchRange(arr, target);
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

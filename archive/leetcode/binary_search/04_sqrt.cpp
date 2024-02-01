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
 *    Find the square root of a number using binary search
 *      integer square-root - e.g. sqrt(12) = 3
 *
 ** @approach -
 * Integer sqrt -
 *  method 1 -
     *   Integer Squareroot of a number that isnt a perfect square
     *   will be the sqrt of the perfect square less than it
     *   therefore sqrt(8) is 2 & sqrt(10) is 3
     *   so we find the highest value where val*val <= x
     *   (since if x = 5 1*1 is also <= x but isnt the ans)
 * Double sqrt -

 */
// classes & functions
class Solution
{
public:
    int mySqrt(int x)
    {
        ll res = -1;
        ll lo = 0, hi = x;
        while (hi - lo > 1)
        {
            ll mid = lo + (hi - lo) / 2;
            ll midSq = mid * mid;
            debug(mid, midSq);
            if (midSq <= x)
            {
                lo = mid;
            }
            else
            {
                hi = mid - 1;
            }
        }
        int loSq = lo * lo, hiSq = hi * hi;
        debug(lo, loSq);
        debug(hi, hiSq);
        if (loSq <= x)
            res = lo;
        if (hiSq <= x)
            res = hi;
        return res;
    }
};
void code()
{
    Solution s;
    int x;
    cin >> x;
    int res = s.mySqrt(x); // store return value
    cout << res << endl;
}

int main()
{
    // Start time
    auto start = chrono::steady_clock::now();

    // fast io
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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
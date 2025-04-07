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
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef priority_queue<int> pqb;
typedef priority_queue<int, vector<int>, greater<int>> pqs;

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
 * @brief- Given a sorted array with both negative & positive numbers,
 *         Return a array with every sqaured and maintain the sorted order
 *
 ** Approach -
      1) Simply square each element and sort them again.

      2) Bucket sort - Maximum possible value if given 10^4.so we can make a count array of size 10^4
         & use count sort to sort the array. while adding elem in the final array, sqaure it.

      3) Two pointers - take left & right ptrs & create a res vector of size n.
                        now compare arr[l] & arr[r] (absolute values) & push the greater value from the end of res
                        (or push it the start and reverse res at the end)
                        We only push n (size of original arr) into res & hence stop the process when all the elements are pushed
 */
// classes & functions
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &arr)
    {
        vi res;
        int n = arr.size();
        int l = 0, r = n - 1;
        for (int i = 0; i < n; ++i)
        {
            int left = abs(arr[l]);
            int right = abs(arr[r]);
            if (left < right)
            {
                res.pb(right * right);
                r--;
            }
            else
            {
                res.pb(left * left);
                l++;
            }
        }
        reverse(all(res));
        return res;
    }

    // Sqaure each element & sort the array again.
    vector<int> sortedSquares2(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            nums[i] *= nums[i];
        }
        sort(all(nums));
        return nums;
    }
};
void code()
{
    Solution s;
    vi arr;
    inVec(arr);
    vi res = s.sortedSquares(arr); // store return value
    debcon(res);
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

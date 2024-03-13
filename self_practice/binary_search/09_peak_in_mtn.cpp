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

// Data structures
struct BinTree
{
    int val;
    BinTree *left;
    BinTree *right;
    BinTree() {}
    BinTree(int val) : val(val), left(nullptr), right(nullptr) {}
};

// Function declarations
BinTree *createTree(vector<int> &nodes);

/**
        @brief -

            * we need to find -> arr[i]  such that arr[i - 1] < arr[i] > arr[i + 1]

            * At start
              ... arr[i - 2] < arr[i - 1] < arr[i] > arr[i + 1] > arr[i + 2] ...
                    lo                                              hi

            * now we move lo to mid + 1 when arr[i] < arr[i + 1], & hi to mid when arr[i] > ar[i + 1]
              not hi - 1 since, hi can be our answer

            * since our exit condn is hi - lo > 1
              After exit lo & hi will be
              arr[i - 1] < arr[i] > arr[i + 1]
                             lo          hi
              arr[i - 1] < arr[i] > arr[i + 1]
                   lo         hi
            Ans is the greater number.
*/
// classes & functions
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &nums)
    {
        int mid;
        int lo = 0, hi = nums.size() - 1, res = -1;

        while (hi - lo > 1)
        {
            mid = lo + (hi - lo) / 2;
            debug(nums[lo], nums[mid], nums[hi]);
            if (nums[mid] < nums[mid + 1])
            {
                lo = mid + 1;
            }
            else if (nums[mid] > nums[mid + 1]) // this is actually else condition
            {
                hi = mid;
            }
        }
        debug(nums[lo], nums[mid], nums[hi]);
        res = hi;
        if (nums[lo] > nums[hi])
            res = lo;
        return res;
    }
};

void code()
{
    Solution s;
    vi arr;
    inVec(arr);
    int res = s.peakIndexInMountainArray(arr);
    cout << res << " " << arr[res] << "\n";
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

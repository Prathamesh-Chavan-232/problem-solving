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
 * @brief-
 *
 * Brute force -
 *      Start from the end & when we encounter a 0 (at index j for instance)
 *      swap num[j] & num[j + 1]
 *
 * Optimal -
 *    Push non zero elements in a new array & count the number of 0s in the array
 *    At the end push the required number of zeros
 *
 *
 * Optimal with O(1) space
 *    0 1 0 3 12
 *    i j
 *    Swap & move both ptrs forward if they arent consecutive zeros & nums[i] is zero
 *    If they're consecutive zeros move j forward
 *    if i & j both have zeros & they arent consecutive only incre i
 */
// classes & functions
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0, j = 1;
        while (j < n)
        {
            if (i == j + 1 && nums[i] == 0 && nums[j] != 0)
            {
                swap(nums[i++], nums[j++]);
            }
            if (nums[i] == 0 && nums[j] != 0)
            {
                swap(nums[i++], nums[j]);
            }
            if (nums[i] == 0 && nums[j] == 0)
            {
                j++;
            }
        }
    }
    void moveZeroes2(vector<int> &nums)
    {
        vi res;
        int n = nums.size(), ct = 0;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] == 0)
                ct++;
            else
                res.pb(nums[i]);
        }
        for (int i = 0; i < ct; ++i)
        {
            res.pb(0);
        }
        nums = res;
    }
    void moveZeroes1(vector<int> &nums)
    {
        int n = nums.size(), z = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            if (nums[i] == 0)
            {
                for (int j = i; j < n - z - 1; ++j)
                {
                    swap(nums[j], nums[j + 1]);
                }
                z++;
            }
        }
    }
};
void code()
{
    Solution s;
    vi nums;
    inVec(nums);
    s.moveZeroes(nums); // store return value
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
    freopen("/home/falconcodes/prathamesh/programming/input.txt", "r", stdin);
    freopen("/home/falconcodes/prathamesh/programming/output.txt", "w", stdout);
    freopen("/home/falconcodes/prathamesh/programming/err.txt", "w", stderr);
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

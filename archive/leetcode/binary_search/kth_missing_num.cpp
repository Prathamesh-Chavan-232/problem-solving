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
 *@brief-
    Find the kth missing number
 ** @approach -
        1> O(n) approach -
                compare array elements with natural numbers.
                when a number is missing count it as missing. Therefore reduce k by 1
                Find the kth number by doing the k times

                If the we run out of array elements & k is still greater than 0.
                It means kth num is arr[n - 1] + k

        2> Binary search approach -
 */
// classes & functions
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int i = 0, num = 1, missing = 0;
        while (i < arr.size())
        {

            if (arr[i] == num)
            {
                num++;
                i++;
            }
            else
            {
                missing = num;
                num++;
                k--;
            }

            if (k == 0)
                break;
        }
        if (k > 0)
        {
            int n = arr.size();
            missing = arr[n - 1] + k;
            debug(missing);
            debug(missing);
        }
        return missing;
    }
};

void code()
{
    Solution s;
    int k;
    vi arr;
    inVec(arr);
    cin >> k;
    int res = s.findKthPositive(arr, k); // store return value
    cout << res << endl;
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

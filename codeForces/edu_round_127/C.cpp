#include <io.h>
#include <bits/stdc++.h>
using namespace std;

// Shortening syntax
#define ll long long
#define fo(i, n) for (ll i = 0; i < n; ++i)
#define Fo(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? ++i : --i)
#define pb push_back
#define mp make_pair
#define pqb priority_queue<int>
#define pqs priority_queue<int, vector<int>, greater<int>>
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define foreach(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define formap(m) for (auto [key, value] : m)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Typdefs for containers
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<int, int> mii;
typedef map<ll, ll> ml;
typedef set<ll> sl;
typedef unordered_map<int, int> umii;
typedef unordered_map<ll, ll> uml;
typedef unordered_set<ll> usl;

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

#ifndef ONLINE_JUDGE
#define debmap(x)        \
    cerr << #x << " = "; \
    _printmap(x);        \
    cerr << "\n";
#else
#define debmap(x)
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
void _print(T const &c) // print any type of vector / set
{
    cerr << "{ ";
    foreach (it, c)
        cerr << *it << ", ";
    cerr << "}";
}

template <typename T, typename U>
void _printmap(map<T, U> m)
{
    cerr << "{ ";
    formap(m)
    {
        cerr << "{" << key << "," << value << "} ";
    }
    cerr << "}";
}
// Varadiac I/O
template <typename... T>
void r(T &...args)
{
    ((cin >> args), ...);
}
template <typename... T>
void w(T &&...args)
{
    ((cout << args << " "), ...);
    cout << "\n";
}
// constants
const int mod = 1'000'000'007;
const int N = 1e7, M = N;
const double PI = 3.1415926535897932384626;

/*
    Link - https://codeforces.com/contest/1671/problem/C
    Problem - Dolce Vita
    Difficulty - Easy
    contest - Educational round 127
    Status - Solved
    Date - 22/4/22, upsolve - 23/4/22 (3 am)
*/

/*  Approach -

    Brute - Sort the array and Linearly simulate the given problem description.
            i.e. calculate the no of sugar bags bought each day, increase price
            until its possible (Gives TLE)

    Better - Determine the no of days for which sugar bags can be bought from each shop
            add the no of days of each shop for final answer.

            formula - to buy the sugar bags for ith shop on nth day
                x >= prefix_sum[i] + (i + 1)*(n - 1) -> we start at day 1  -- -- -- (1)
                (Since to buy from the ith shop we will also have to buy from
                all the previous shops and the price of the bags in those shops will increase by n on the nth day)

                therefore to find the nth day
                n = ((x - prefix_sum[i]) / (i + 1)) + 1     -- -- -- (2)
                find the nth day for each element, finally res += n 

    Optimal - Use binary search to determine for how many days can we buy from a
            particular shop. (similar to prev approach just here we use binary search to find n, use (1) for this)
*/

void solve()
{
    int n, x;
    cin >> n >> x;
    vl arr(n, 0);
    Fo(i, 0, n)
    {
        cin >> arr[i];
    }
    sort(all(arr));
    ll res = 0, last = 0;
    for (int i = 0; i < n; ++i)
    {
        last += arr[i];
        if ((x - last) >= 0)
        {
            res += ((x - last) / (i + 1)) + 1;
            debug(x, last, res);
        }
    }
    cout << res << "\n";
}
int main()
{
    auto start = chrono::steady_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:/Prathamesh/Programming/input.txt", "r", stdin);
    freopen("C:/Prathamesh/Programming/output.txt", "w", stdout);
    freopen("C:/Prathamesh/Programming/err.txt", "w", stderr);
#endif
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
#ifndef ONLINE_JUDGE
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "[Finished in " << setprecision(3) << chrono::duration<double, milli>(diff).count() << " ms]\n";
#endif
    return 0;
}

void brute() // gives TLE
{
    int n;
    ll x;
    scanf("%d", &n);
    scanf("%lld", &x);
    vl arr(n);
    fo(i, n) scanf("%lld", &arr[i]);

    int i = 0;
    ll money = x;
    ll res = 0;
    sort(all(arr));

    while (x >= arr[0])
    {
        fo(i, n)
        {
            if (arr[i] <= money)
            {
                money -= arr[i];
                res++;
            }
            debug(arr[i], money, res);
            arr[i]++;
        }
        money = x;
        cerr << "\n";
    }

    printf("%lld\n", res);
}

void optimal()
{
    int n;
    ll x;
    scanf("%d", &n);
    scanf("%lld", &x);
    vl arr(n);
    fo(i, n) scanf("%lld", &arr[i]);

    int i = 0;
    ll money = x;
    ll res = 0;
    sort(all(arr));
    //
    int low = 0, high = INT_MAX;
}
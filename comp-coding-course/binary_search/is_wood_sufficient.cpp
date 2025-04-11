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
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

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

// STL vector / set (of any type) debugger
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
        cerr << *it << ", ";
    }
    cerr << "}";
}

// Function definitions
void addEdge(int v1, int v2);
void dfs(int vertex);

// constants
const int mod = 1'000'000'007;
const int N = 1e6, M = N;
const double PI = 3.1415926535897932384626;

vi graph[N]; // For Adjacency List
bool vis[N];

// Binary search using predicate functions
/*
    Link -
    Problem -
    Difficulty -
    contest -
    Status -
    Date -
*/
/*  Approach -

*/

int n;
ll m;
vi trees(N);

bool isWoodSufficient(int h)
{
    ll wood = 0;
    fo(i, n)
    {
        if (trees[i] >= h)
        {
            wood += (trees[i] - h);
        }
    }
    return wood >= m;
}
ll bin_search()
{
    ll l = 0, r = 1e9;
    while (r - l > 1)
    {
        ll mid = (l + r) / 2;
        if (isWoodSufficient(mid))
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    ll res;
    if (isWoodSufficient(r))
    {
        res = r;
    }
    else
    {
        res = l;
    }
    return res;
}
void code()
{
    cin >> n >> m;
    fo(i, n)
    {
        cin >> trees[i];
    }
    ll res = bin_search();
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
    freopen("C:/Prathamesh/Programming/input.txt", "r", stdin);
    freopen("C:/Prathamesh/Programming/output.txt", "w", stdout);
    freopen("C:/Prathamesh/Programming/err.txt", "w", stderr);
#endif

    // Running for multiple testcases / queries
    int t = 1;
    cin >> t;
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
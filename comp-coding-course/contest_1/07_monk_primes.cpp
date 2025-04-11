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
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)

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
    Link - https://www.hackerearth.com/problem/algorithm/monk-and-his-love-for-primes/
    Problem - monk and has love for primes
    Difficulty - Easy
    contest - Contest 1, cp course
    Status - solved
    Date - 22/4/22
*/
/*
Approach -

*/

void solve()
{
    string s;
    r(s);
    int res = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] >= 'A' && s[i] <= 'Z') // if uppercase convert to lowercase
        {
            s[i] = s[i] - 'A' + 'a';
            res -= (int)s[i]; // subtract lowercase letters
        }
        else if (s[i] >= 'a' && s[i] <= 'z') // if lowercase convert to uppercase
        {
            s[i] = s[i] - 'a' + 'A';
            res += (int)s[i]; // Add uppercase letters
        }
        debug(s[i], res);
    }
    res = abs(res);
    int flag = 1;
    debug(res);
    for (int i = 2; i < sqrt(res); i++)
    {
        if (res % i == 0)
        {
            flag = 0;
            break;
        }
    }
    printf("%d\n", flag);
}
int main()
{

    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:/Prathamesh/Programming/input.txt", "r", stdin);
    freopen("C:/Prathamesh/Programming/output.txt", "w", stdout);
    freopen("C:/Prathamesh/Programming/err.txt", "w", stderr);
#endif
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        solve();
    }
    return 0;
}
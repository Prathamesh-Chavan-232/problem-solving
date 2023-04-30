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
    Link - https://codeforces.com/contest/1671/problem/A
    Problem - String building
    Difficulty - Very Easy
    contest - Edu round 127 
    Status - Solved
    Date - 22/4/22, upsolve - 23/4/22 (1 am)
*/
/* Approach -

    Smart Approach -
        As per the given data,
            only the strings aa, aaa, bb,bbb and multiples of them are possible
        So,
            Strings like a,b,ab,ba,bab or aba aren't possible
        Therefore,
            if an for an element, if s[i] != s[i - 1] && s[i] != s[i + 1], its not possible
*/

void solve()
{
    string s, res = "YES";
    r(s);
    int n = s.size();
    s = "?" + s + "?";  // Adding random characters at the start and end to handle the edge case
    
    Fo(i, 1, n + 1) // start from 1 & go to n since 0 and n + 1 have random characters
    {
        if (s[i] != s[i + 1] && s[i] != s[i - 1])
        {
            res = "NO";
            break;
        }
    }
    w(res);
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
    scanf("%d", &t);
    while (t--)
    {
        solve();
    }
    return 0;
}

/*  My Approach -
        As per the given data,
            only the strings aa, aaa, bb,bbb and multiples of them are possible
        so,
            strings like a,b, ab,ababab.... etc are not possible

        I treated every sub-string as a different string if the consecutive elements weren't
        equal
        so aaaa...was one string until it only had 'a'
        so ababab... cases were divided into single 'a' or 'b' strings which meant they were impossible
*/
bool chk_string(string temp)
{
    return temp.size() > 1 ? true : false;
}
void tedious()
{
    string s, res = "YES";
    r(s);
    int n = s.size();
    if (n <= 1)
    {
        res = "NO";
    }
    else
    {
        int i = 0;
        string temp = "";
        temp += s[i++];

        while (i <= n)
        {
            debug(i);
            if (s[i] == s[i - 1])
            {
                temp += s[i];
                i++;
            }
            else
            {
                debug(temp, chk_string(temp)); // checking for substrings 'a' and 'b'
                if (!chk_string(temp))
                {
                    res = "NO";
                    break;
                }
                else
                {
                    temp = s[i];
                    if (i != n - 1) // if we increment at n - 1 we might not check the last character
                    {
                        i++;
                    }
                    debug(i, temp);
                }
            }
        }
    }
    w(res);
    cerr << "\n\n";
}

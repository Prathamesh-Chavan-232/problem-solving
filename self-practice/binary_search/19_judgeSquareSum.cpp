#include <bits/stdc++.h>
using namespace std;

// Shortening syntax
#define fo(i, n) for (int i = 0; i < n; ++i)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? ++i : --i)
#define ll long long
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
    Link - https://leetcode.com/problems/sum-of-square-numbers/
    Problem - Sum of squares
    Difficulty - medium
    contest - no
    topic - Binary search
    Status - solved with 1 hint
    Date - 15/4/22

Approach -
    we need to prove a^2 + b^2 = c
    where a & b are arbitrary
    take a = 1 to sqrt(c)
    for each a, check whether c - a^2 is a perfect square
    Use binary search to check for perfect square.

*/
class Brute
{
public:
    bool judgeSquareSum(int c)
    {
        int rootc = sqrt(c);
        Fo(i, 1, rootc + 1)
        {
            Fo(j, i, rootc + 1)
            {
                if (i * i + j * j == c)
                {
                    w(i, "^", i, "+", j, "^", j, "=", c);
                    return true;
                }
            }
        }
        return false;
    }
};
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        bool res = false;
        int low = 0, high = num;
        ll target;
        while (low <= high)
        {
            ll mid = low + (high - low) / 2;
            target = (mid * mid);
            if (target == num)
            {
                res = true;
                break;
            }
            else if (target < num)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return res;
    }
    bool judgeSquareSum(int c)
    {
        int rootc = sqrt(c);
        Fo(i, 1, rootc + 1)
        {
            int num = c - (i * i);
            if (isPerfectSquare(num))
            {
                num = sqrt(num);
                w(i, "^", i, "+", num, "^", num, "=", c);
                return true;
            }
        }
        return false;
    }
};

int main()
{
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:/Prathamesh/Programming/input.txt", "r", stdin);
    freopen("C:/Prathamesh/Programming/output.txt", "w", stdout);
    freopen("C:/Prathamesh/Programming/err.txt", "w", stderr);
#endif

    Solution s;
    int c;
    scanf("%d", &c);
    bool res = s.judgeSquareSum(c); // store return value
    printf("%d\n", res);
    return 0;
}
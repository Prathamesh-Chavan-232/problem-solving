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
        else if (s[i] == ',')
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
void Add_edge(int v1, int v2);
void dfs(int vertex);

// constants
const int mod = 1000000007;
const int N = 1e5 + 10, M = N;
const double PI = 3.1415926535897932384626;

vpii graph[N]; // For Adjacency List
bool vis[N];

/*
    Link - https://www.codingninjas.com/codestudio/problems/chess-tournament_981299?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
    Problem - SDE Sheet - Aggressive cows
    Difficulty - Medium/hard
    Topic - Binary Search
    Status - Solved
    Date - 20/6/22
*/
/*  Approach -

        [ 1 , 2 , 4 , 8 , 9 ]      minDist
          c   c   c                   1
          c       c       c           3
          c           c   c           1
          c       c   c               3
          
        we can place cows on given positions, We need to place the cows such that
            ->   the minimum distance from the distances between any 2 cows is maximised
        Here the Max possible value of minDist is 3

        We can create a predicate function which will return true if we can place all cows for minDist <= X
        Once it starts returning false we cant imcrease minDist anymore and hence find the answer

        Predicate function - It places cow a one position if arr[i] >= lastPos + minDist 
*/
bool canPlaceCows(vi arr, int c, int minDist)
{
    int lastPos = -1;
    int n = arr.size();
    for (int i = 0; i < n; ++i)
    {
        if (arr[i]>= lastPos + minDist || lastPos == -1)
        {
            lastPos = arr[i];
            c--;
        }
        if (c == 0)
            break;
    }
    return c == 0;
}
int chessTournament(vector<int> arr, int n, int c)
{
    // Write your code here
    sort(all(arr));
    int lo = 0, hi = 1e9, mid;
    while (hi - lo > 1)
    {
        mid = (hi + lo) / 2;
        if (canPlaceCows(arr, c, mid))
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    if (canPlaceCows(arr, c, hi))
    {
        debug(hi);
        cout << hi << "\n";
    }
    else
    {
        debug(lo);
        cout << lo << "\n";
    }
}

void code()
{

    // vi arr;
    // inVec(arr);
    int res; // store return value
    cout << res << "\n";
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

    code();

// Calculating Runtime
#ifndef ONLINE_JUDGE
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "[Finished in " << setprecision(3) << chrono::duration<double, milli>(diff).count() << " ms]\n";
#endif
    return 0;
}

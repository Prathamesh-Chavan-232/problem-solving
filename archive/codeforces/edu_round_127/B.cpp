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
const int N = 1e6 + 1, M = N;
const double PI = 3.1415926535897932384626;

/*
    Link - https://codeforces.com/contest/1671/problem/B
    Problem - Consecutive points segment
    Difficulty - Very Easy
    contest - Edu round 127
    Status - Solved
    Date - 22/4/22, upsolve - 23/4/22 (2 am)
*/
/*
Approach -

    mistake in my approach -
    1)
        Just checking if diff > 3, wont work everytime coz we can change
        the values of the elements. We need to simulate the change between the elements

    Solution -

    Approach 1) -
        eg - 1 , 3 , 4 , 5

        1st element - 1 can be case 1 : 0,  case 2: 1, or case 3: 2
        Brute will be to lock 1st element's value to one of 3 possiblities
        and the operate the rest of the array for checking if it satisfies the condition

        But after simulating for case 2 i.e. no change case
        we can prove that is that case is true, then case 3 will automatically be true.

        Therefore, first element will always be incremented and others will stay the same or be decremented
        if after incrementing arr[i - 1] (arr[0]) arr[i] - arr[i - 1] becomes 0, then arr[i] will be incremented

        Therefore,
            diff = 0, incre
            diff = 1, nothing
            diff = 2, decre
            diff >= 3, not possible, exit

    Approach 2)

        End goal - make the numbers consecutive
            For consecutive numbers - no of elements = last - first + 1
            (since its x, x + 1, x + 2,.... ,x + n - 1)

            First element should be incremented / no change
            Last element can be decremented / no change
            incrementing last element -> will increase diff so we wont do that

            last : no change, 1st : no change -> arr[n - 1] - arr[0] + 1 == n
            last : decre, 1st : No change -> arr[n - 1] - 1 - arr[0] == n
            last : no change, 1st : incre -> arr[n - 1] - arr[0] - 1 == n
            last : decre, 1st : incre ->  arr[n - 1] - arr[0] - 2 == n

            Therefore the conditions are -
                arr[n - 1] - arr[0] - 1 == n || arr[n - 1] - arr[0] - 2 == n || arr[n - 1] - arr[0] + 1 == n
            which can also be written like
                arr[n - 1] - arr[0] - 1 <= n

*/

void func();

void approach2()
{
    int n;
    scanf("%d", &n);
    vi arr(n);
    fo(i, n)
    {
        scanf("%d", &arr[i]);
    }
    int diff = arr[n - 1] - arr[0] - 1;
    if (diff <= n)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}
void solve()
{
    int n;
    scanf("%d", &n);
    vi arr(n);
    fo(i, n)
    {
        scanf("%d", &arr[i]);
    }
    arr[0] += 1;
    string res = "YES";
    Fo(i, 1, n)
    {
        int diff = arr[i] - arr[i - 1];
        if (diff == 0)
        {
            arr[i]++;
        }
        else if (diff == 2)
        {
            arr[i]--;
        }
        else if (diff >= 3)
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
        approach2();
    }
    return 0;
}

// Cant understand the approach in this one.
void func()
{
    int n;
    scanf("%d", &n);
    vi arr(n);
    fo(i, n)
    {
        scanf("%d", &arr[i]);
    }
    int diff = 0;

    string res = "YES";
    fo(i, n - 1)
    {
        diff += arr[i + 1] - arr[i] - 1;
        debug(arr[i + 1], arr[i]);
        debug(diff);
        if (diff > 2)
        {
            res = "NO";
            break;
        }
    }
    w(res);
}
#include <bits/stdc++.h>
#include <io.h>
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
#define debcon(x)                                                              \
  cerr << #x << " = ";                                                         \
  _print(x);                                                                   \
  cerr << "\n";
#else
#define debcon(x)
#endif

#ifndef ONLINE_JUDGE
#define debmap(x)                                                              \
  cerr << #x << " = ";                                                         \
  _printmap(x);                                                                \
  cerr << "\n";
#else
#define debmap(x)
#endif

// Function definitions
template <typename... Args>
void logger(string varname,
            Args &&...values) // logger for varadiac debugging print statements
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

template <typename T, typename U> void _printmap(map<T, U> m) {
  cerr << "{ ";
  formap(m) { cerr << "{" << key << "," << value << "} "; }
  cerr << "}";
}
// Varadiac I/O
template <typename... T> void r(T &...args) { ((cin >> args), ...); }
template <typename... T> void w(T &&...args) {
  ((cout << args << " "), ...);
  cout << "\n";
}
// constants
const int mod = 1'000'000'007;
const int N = 1e7, M = N;
const double PI = 3.1415926535897932384626;

/*
    Link - https://codeforces.com/contest/1674/problem/B
    Problem - B. Dictionary
    Difficulty - Easy
    contest - Round 786
    Status - Solved during contest
    Date - 02/5/22
*/
/*  Approach -
    dictionary consists of

    ab ac ad ... az   ba - bz  ... ... ... .... za - zy
     1  2  3     25   26   50                   626  650

    There are different sets in which the dictionary is divided
    a _ ,  b _ , c _ , ... (each set will have 25 words) and there are 26 such
   sets for total 650 words 1 - 25,26 - 50 , ...

    Therfore we find the set by doing s[0]*25 Add s[1] for the exact index
    Since we have to skip words with equal letters if 1st letter > 2nd letter if
   subtract 1 from its rank

    since,
    ba bb bc bd be ...
    26 _  27 28 29 ...
*/

void solve() {
  string s;
  cin >> s;
  int rank = 0;
  int temp = (int)(s[1] - 'a' + 1);
  debug(temp);
  rank +=
      (int)(s[0] - 'a') * 25; // calculates which set it belongs, 1, 25, 50 etc
  rank += (int)(s[1] - 'a') + 1; // position inside the set
  if (s[0] < s[1])               // decreasing rank after skipping equal string
  {
    rank--;
  }
  cout << rank << endl;
}
int main() {
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

  while (t--) {
    solve();
  }
#ifndef ONLINE_JUDGE
  auto end = chrono::steady_clock::now();
  auto diff = end - start;
  cerr << "[Finished in " << setprecision(3)
       << chrono::duration<double, milli>(diff).count() << " ms]\n";
#endif
  return 0;
}

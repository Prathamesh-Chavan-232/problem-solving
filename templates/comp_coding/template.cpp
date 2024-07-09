#include <bits/stdc++.h>
using namespace std;

// Shortening syntax
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

// DP
#define clr(x) memset(x, 0, sizeof(x))

// Randomizer
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
typedef priority_queue<int> pqb;
typedef priority_queue<int, vector<int>, greater<int>> pqs;

// Varidiac Variable debugger
#ifndef ONLINE_JUDGE
#define debug(...) logger(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#endif
template <typename... Args>
void logger(string varname,
            Args &&...values) // logger for varadiac debugging print statements
{
  cerr << varname << " =";
  string delim = " ";
  (..., (cerr << delim << values, delim = ", "));
  cerr << "\n";
}

// Debugger for STL vector / set (of any type)
#ifndef ONLINE_JUDGE
#define debvec(x)                                                              \
  cerr << #x << " = ";                                                         \
  _print(x);                                                                   \
  cerr << "\n";
#else
#define debvec(x)
#endif
template <typename T> void _print(T const &c) {
  cerr << "{ ";
  for (auto it = c.begin(); it != c.end(); it++) {
    it != --c.end() ? cerr << *it << ", " : cerr << *it;
  }
  cerr << "}";
}

// Data structures
struct BinTree {
  int val;
  BinTree *left;
  BinTree *right;
  BinTree() {}
  BinTree(int val) : val(val), left(nullptr), right(nullptr) {}
};

// Function declarations
BinTree *createTree(vector<int> &nodes);
void addEdge(int v1, int v2);
void dfs(int rtex);

// constants
const int mod = 1'000'000'007;
const int N = 1e5 + 10, M = N;
const double PI = 3.1415926535897932384626;

// global variables
vi graph[N]; // For Adjacency List
bool vis[N];

/*
    Link -
    Problem -
    Difficulty -
    Topic -
    Status -
    Date -
*/
/*  Approach -

*/

// classes & functions
void code() {
  // Think Clearly.
}

int main() {
  // Start time
  auto start = chrono::steady_clock::now();

  // fast io
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

// Input, Output & error messages inside text files
#ifndef ONLINE_JUDGE
  freopen("/home/falconcodes/keep-coding/coding-practice/input.txt", "r",
          stdin);
  freopen("/home/falconcodes/keep-coding/coding-practice/output.txt", "w",
          stdout);
  freopen("/home/falconcodes/keep-coding/coding-practice/err.txt", "w", stderr);
#endif

  int t = 1;
  cin >> t;
  while (t--) {
    code();
  }

// Calculating Runtime
#ifndef ONLINE_JUDGE
  auto end = chrono::steady_clock::now();
  auto diff = end - start;
  cerr << "[Finished in " << setprecision(3)
       << chrono::duration<double, milli>(diff).count() << " ms]\n";
#endif
  return 0;
}

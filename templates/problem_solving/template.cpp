#include <bits/stdc++.h>
using namespace std;

// Shortening syntax
#define ll long long
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
void inVec(vector<int> &v) {
  string s;
  getline(cin, s);
  int num = 0, sign = 1;

  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '[' || s[i] == ']')
      continue;
    if (s[i] == '-')
      sign = -1;
    else if (s[i] == ',' || s[i] == ' ')
      v.push_back(num), num = 0;
    else {
      num = num * 10 + (s[i] - '0');
      num *= sign;
      sign = 1;
    }
  }
  v.push_back(num);
}

// Variable debugger
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

// STL Container Debugger 
const int mod = 1e9 + 7;
const int N = 1e5 + 10, M = N;
const double PI = 3.1415926535897932384626;
const int mod = 1e9 + 7;
const int N = 1e5 + 10, M = N;
const double PI = 3.1415926535897932384626;
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

// constants
const int mod = 1e9 + 7;
const int N = 1e5 + 10, M = N;
const double PI = 3.1415926535897932384626;

/**
 * @brief-
 *
 *
 */

// Global variables
vi graph[N];
bool vis[N];

// classes & functions
class Solution {
public:
    void func() {
        // Think First.
    }
};

void run() {
  // Think First.
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
  // cin >> t;
  while (t--) {
    run();
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


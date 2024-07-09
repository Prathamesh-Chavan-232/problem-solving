#include <bits/stdc++.h>
using namespace std;

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


/**
 * @desc -
 *
 *
 */

// constants
const int mod = 1e9 + 7;
const int N = 1e5 + 10, M = N;
const double PI = 3.1415926535897932384626;

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

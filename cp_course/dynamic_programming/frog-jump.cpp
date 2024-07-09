#include <bits/stdc++.h>
using namespace std;

/**
 * @desc -
 *
 *
 */

// constants
const int mod = 1e9 + 7;
const int N = 1e5 + 10, M = N;
const double PI = 3.1415926535897932384626;

int h[N], dp[N];

class Solution {
public:
  int frogJump(int i) {
    if (i == 0)
      return 0;
    if (dp[i] != -1)
      return dp[i];

    int cost = 0;
    cost = min(cost, abs(h[i] - h[i - 1]) + frogJump(i - 1));
    cost = min(cost, abs(h[i] - h[i - 2]) + frogJump(i - 2));

    return dp[i] = cost;
  }
};

void run() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  Solution s;
  int res = s.frogJump(n - 1);
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

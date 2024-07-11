#include <bits/stdc++.h>
using namespace std;

/**
 * @desc -
    There are N stones, numbered 1,2,…,N. For each i ( 1≤i≤N), the height of
    Stone i is h[i]

    There is a frog who is initially on Stone 1. He will repeat the following
    action some number of times to reach Stone N:

    If the frog is currently on Stone i, jump to one of the following: Stone
    i+1,i+2,…,i+K. Here, a cost of abs(h[i] - h[j]) is incurred, where j is the
    stone to land on.

    Find the minimum possible total cost incurred before the frog reaches Stone
    N.

 */

// constants
const double PI = 3.1415926535897932384626;
const int mod = 1e9 + 7;

const int N = 1e5 + 10, M = N;
int k = 2, h[N], dp[N];

int frogAtCoder(int i) {
  if (i == 0)
    return 0;
  if (dp[i] != -1)
    return dp[i];

  int cost = INT_MAX;
  for (int j = 1; j <= k; j++) {
    if (i - j >= 0)
      cost = min(cost, abs(h[i] - h[i - j]) + frogAtCoder(i - j));
  }

  return dp[i] = cost;
}

void run() {
  int n;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }

  memset(dp, -1, sizeof(dp));
  int res = frogAtCoder(n - 1);
  cout << res << "\n";
}

int main() {

  // fast io
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

// Input, Output & error messages inside text files
#ifndef ONLINE_JUDGE
  // Start time
  auto start = chrono::steady_clock::now();

  freopen("/home/falconcodes-noovosoft/keep-coding/personal/coding-practice/"
          "input.txt",
          "r", stdin);
  freopen("/home/falconcodes-noovosoft/keep-coding/personal/coding-practice/"
          "output.txt",
          "w", stdout);
  freopen("/home/falconcodes-noovosoft/keep-coding/personal/coding-practice/"
          "error.txt",
          "w", stderr);
#endif

  int t = 1;
  // cin >> t;
  while (t--) {
    run();
  }

// Calculate Runtime
#ifndef ONLINE_JUDGE
  auto end = chrono::steady_clock::now();
  auto diff = end - start;
  cerr << "[Finished in " << setprecision(3)
       << chrono::duration<double, milli>(diff).count() << " ms]\n";
#endif

  return 0;
}

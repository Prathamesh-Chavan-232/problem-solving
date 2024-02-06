#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

#define debug(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename... Args> void logger(string varname, Args &&...values) {
  cerr << varname << " = ";
  string delim = "";
  (..., (cerr << delim << values, delim = ", "));
  cerr << "\n";
}

// Vector Debugger
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
    cerr << *it << ", ";
  }
  cerr << "}";
}

/**
 * (Recursion & Backtracking)
 * @brief - Find all the arrs & print the next arr
 *
 * @solution - This is solution can be achieved by swapping since all the arrays
 * will have the same size
 *
 *
 */

vector<vector<int>> res; // list of all permutations
class Solution {

public:
  void permute(vector<int> &arr, int index) {
    // base condition
    if (index == arr.size()) {
      res.push_back(arr);
      return;
    }
    for (int i = index; i < arr.size(); i++) {
      swap(arr[index], arr[i]); // Choice 1 -> Swap with self
      permute(arr, index + 1);  // recursion
      swap(arr[index], arr[i]); // Backtrack choice 1
    }
  }
};

void code() {
  // Think first.
  Solution s;
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  s.permute(arr, 0);

  for (auto arr : res) {
    debvec(arr);
  }
}
int main() {
  auto start = chrono::steady_clock::now();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
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
#ifndef ONLINE_JUDGE
  auto end = chrono::steady_clock::now();
  auto diff = end - start;
  cerr << "[Finished in " << setprecision(3)
       << chrono::duration<double, milli>(diff).count() << " ms]\n";
#endif
  return 0;
}

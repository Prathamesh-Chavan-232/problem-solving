#include <bits/stdc++.h>
using namespace std;

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
 * @brief- Find the next lexiographically greater permutation of an array, if
 * there isn't any, return the lexiographically smallest one
 *
 * Brute Force - Find all the permutations & print the next permutation
 * (Recursion & Backtracking)
 *
 * Optimal - {2,1,5,4,3,0,0} - find the breakpoint where arr[i] < arr[i+1] from
 * the back of the array?
 */

class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    int breakpoint = -1;
    for (int i = nums.size() - 2; i >= 0; i--) {
      if (nums[i] < nums[i + 1]) {
        breakpoint = i;
        debug(nums[breakpoint], nums[i + 1]);
      }
    }
    if (breakpoint == -1) {
      reverse(nums.begin(), nums.end());
    } else {
      int nextMaxPtr = nums[breakpoint];
      for (int i = breakpoint + 1; i < nums.size(); i++) {
        if (nums[i] > nextMaxPtr || nums[i] > nums[breakpoint]) {
          nextMaxPtr = i;
        }
      }
      debug(nums[nextMaxPtr]);
      swap(nums[breakpoint], nums[nextMaxPtr]);
      sort(nums.begin() + breakpoint + 1, nums.end());
    }
    debvec(nums);
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
  s.nextPermutation(arr);
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

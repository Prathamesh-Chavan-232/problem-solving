#include <bits/stdc++.h>
using namespace std;

/**
 * Approach - 2 pointer
   Description -

        In this approach we attempt to use constant space by eliminating the set
 required  to track unique triplets.
        1. Sort the array first so all the duplicates are adjacent.
        2. for a triplet we will need 3 pointers where the sum of the values of
 these pointers should be zero.

        3. we can place our pointers like this -
                1 2 _ _ _ _ 3
                i j         k
                Take a for loop of i = 0 to n - 1, i will be our 1st pointer.
                for each iteration i will be static and we will move j & k to
 find the triplet while avoiding duplicates. (This is very similar to binary
 search)

        4. Cases:
            sum < 0 -> need greater num increment j
            sum > 0 -> need smaller num decrement k
            sum = 0 -> found triplet, add its vector and skip duplicates
 */

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (i != 0 && nums[i] == nums[i - 1])
        continue;

      int j = i + 1, k = n - 1;
      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];
        if (sum < 0) {
          j++;
        } else if (sum > 0) {
          k--;
        } else {
          vector<int> triplet = {nums[i], nums[j], nums[k]};
          ans.push_back(triplet);

          j++;
          k--;

          while (j < n && nums[j] == nums[j - 1]) {
            j++;
          }
          while (k < n && nums[k] == nums[k + 1]) {
            k--;
          }
        }
      }
    }
    return ans;
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

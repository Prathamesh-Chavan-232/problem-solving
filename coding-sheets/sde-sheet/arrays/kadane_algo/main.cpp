#include <bits/stdc++.h>
using namespace std;

// constants
const int N = 1e5 + 10, M = N;

/*
    Link - https://leetcode.com/problems/maximum-subarray/
    Problem - Maximum sum subarray
    Difficulty - Easy
    Topic - Prefix sum & Dynamic programming
*/

/*  Approach -
 *
 *      Brute force - 2 for loops, calculate sum of every subarray. takes its
 maximum.

        Optimal -

        Kadane's algorithm - Logic of the algorithm is the keep
   calculating the sum of the subarray which yeilds us a positive sum, The main
   idea is that if a subarray yeilds negative sum you would definitely skip it
   when selecting the maximum sum subarray.

    Notes -
                1) This way we will definitely go through the required subarray
   & set the maxSum which wont be affected when the sum decreases.

                2) This algorithm's main task is finding the starting point of
   the subarray because after that we will definitely calculate maximum sum, as
   once it becomes maximum it won't change even if we keep going through the
   remaining array.

                3) we calculate sum & assign maxSum before we reset sum, so it
   works even though the array has all negative numbers, at end maxSum will be
   equal to the largest number in the array

                4) If its premitted for the case array containing all negative
   numbers, the answer can also be 0, (which means an empty subarray)

    Psuedocode -
                1) add the current element sum, compare it with maxSum

                2) if the sum is negative. we reset it to 0

*/

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int n = nums.size(), sum = 0;
    int maxSum = nums[0];
    for (int i = 0; i < n; ++i) {
      sum += nums[i];
      maxSum = max(maxSum, sum);

      if (sum < 0)
        sum = 0;
    }
    return maxSum;
  }
};

void code() {
  int t = 1;
  cin >> t;
  cin.ignore();
  while (t--) {
    Solution s;
    vector<int> arr;
    int res = s.maxSubArray(arr); // store return value
    cout << res << "\n";
  }
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

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findDuplicate(vector<int> &nums) {

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != i + 1) {
        int correct = nums[i] - 1;
        if (nums[i] == nums[correct]) {
          return nums[i];
        } else {
          swap(nums[i], nums[correct]);
        }
      }
    }
    return -1;
  }
};

int main() { return 0; }

#include <bits/stdc++.h>
using namespace std;

void code() {
  // Think Clearly.
  int n;
  cin >> n;

  vector<int> arr(n);
  int sum = 0, nMoves = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  cout << sum << endl;
  while (arr.size() > 0) {
    if (sum % 3 == 0) {
      break;
    }
    int temp = (sum / 3) * 3;
    int diff = (temp - sum);
    if (diff == 1) {
      sum++;
      nMoves++;
    } else {
    }
  }
  cout << nMoves << endl;
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

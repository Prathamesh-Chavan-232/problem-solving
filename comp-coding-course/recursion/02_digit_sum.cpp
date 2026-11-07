#include <bits/stdc++.h>
using namespace std;

int digit_sum(int n)
{
    if (n == 0)
        return 0;

    return digit_sum(n / 10) + n % 10;
}

void solve()
{
    int n;
    cin >> n;
    int res = digit_sum(n);
    cout << res << "\n";
}
int main()
{
    auto start = chrono::steady_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
#ifndef ONLINE_JUDGE
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "[Finished in " << setprecision(3) << chrono::duration<double, milli>(diff).count() << " ms]\n";
#endif
    return 0;
}
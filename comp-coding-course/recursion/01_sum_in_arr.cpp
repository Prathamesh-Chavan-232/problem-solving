#include <bits/stdc++.h>
using namespace std;

#define debug(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename... Args>
void logger(string varname, Args &&...values)
{
    cerr << varname << " = ";
    string delim = "";
    (..., (cerr << delim << values, delim = ", "));
    cerr << "\n";
}


int sum_(int arr[], int n)
{
    if (n == 0)
        return arr[0];
    int sum = arr[n] + sum_(arr, n - 1);
    debug(sum);
    return sum;
}
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    int res = sum_(arr, n - 1);
    cout << "res = " << res << "\n";
}
int main()
{
    auto start = chrono::steady_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:/Prathamesh/Programming/input.txt", "r", stdin);
    freopen("C:/Prathamesh/Programming/output.txt", "w", stdout);
    freopen("C:/Prathamesh/Programming/err.txt", "w", stderr);
#endif
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
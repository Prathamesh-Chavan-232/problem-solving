#include <bits/stdc++.h>
using namespace std;

// Varidiac Variable debugger
#ifndef ONLINE_JUDGE
#define debug(...) logger(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#endif
template <typename... Args>
void logger(string varname, Args &&...values) // logger for varadiac debugging print statements
{

    cerr << varname << " =";
    string delim = " ";
    (..., (cerr << delim << values, delim = ", "));
    cerr << "\n";
}

// constants
const int mod = 1'000'000'007;
const int N = 1e7, M = N;
const double PI = 3.1415926535897932384626;

double eps = 1e-5;
/*
    Calculate the nth root of x using binary search
*/
/*  Approach -
        suppose - x = 2, n = 2
        so we need to find square root of 2
        we know that sqrt of 2 is 1.413 ... & is an irrational number
        so if l = 1.4133 and r = 1.4166 (suppose)
        r - l = 0.0033 (so our mid value will be accurate till 2 decimal places if r - l > 1e-3)
*/

double mul(double x, int n)
{
    double y = 1;
    for (int i = 0; i < n; ++i)
    {
        y *= x;
    }
    debug(y);
    return y;
}
double nth_rt(double x, int n)
{

    double l = 0, r = x, res = -1;
    while (r - l > eps)
    {
        double mid = (l + r) / 2.0;
        double nth_rt = mul(mid, n);
        debug(nth_rt);
        if (nth_rt < x)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout << setprecision(10) << l << "\n";
    return r;
}
void code()
{
    double x;
    int n;
    cin >> x >> n;
    // double x = mul(x, n);
    double res = nth_rt(x, n);
    cout << setprecision(10) << res << "\n";
    cout << pow(x, 1.0 / 2);
}

int main()
{
    // Start time
    auto start = chrono::steady_clock::now();

    // fast io
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

// Input, Output & error messages inside text files
#ifndef ONLINE_JUDGE
    freopen("C:/Prathamesh/Programming/input.txt", "r", stdin);
    freopen("C:/Prathamesh/Programming/output.txt", "w", stdout);
    freopen("C:/Prathamesh/Programming/err.txt", "w", stderr);
#endif

    // Running for multiple testcases / queries
    int t = 1;
    // cin >> t;
    while (t--)
    {
        code();
    }

// Calculating Runtime
#ifndef ONLINE_JUDGE
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "[Finished in " << setprecision(3) << chrono::duration<double, milli>(diff).count() << " ms]\n";
#endif
    return 0;
}
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

// Vector Debugger
#ifndef ONLINE_JUDGE
#define debcon(x)        \
    cerr << #x << " = "; \
    _print(x);           \
    cerr << "\n";
#else
#define debcon(x)
#endif
template <typename T>
void _print(T const &c)
{
    cerr << "{ ";
    for (auto it = c.begin(); it != c.end(); it++)
    {
        cerr << *it << ", ";
    }
    cerr << "}";
}

/**
 * @brief-
 *
 *
 */

void code()
{
    // Think first.
}
int main()
{
    auto start = chrono::steady_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/falconcodes/keep-coding/programming/input.txt", "r", stdin);
    freopen("/home/falconcodes/keep-coding/programming/output.txt", "w", stdout);
    freopen("/home/falconcodes/keep-coding/programming/err.txt", "w", stderr);
#endif
    int t = 1;
    cin >> t;
    while (t--)
    {
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
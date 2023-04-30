#include <bits/stdc++.h>
using namespace std;

// Shortening syntax
#define ll long long

// Typdefs for containers
typedef vector<int> vi;
typedef vector<ll> vl;

// Varidiac Variable debugger
#ifndef ONLINE_JUDGE
#define debug(...) logger(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#endif
template <typename... Args>
void logger(string varname, Args &&...values)  // logger for varadiac debugging print statements
{
    cerr << varname << " =";
    string delim = " ";
    (..., (cerr << delim << values, delim = ", "));
    cerr << "\n";
}

// debugger for STL vector / set (of any type)
#ifndef ONLINE_JUDGE
#define debcon(x)        \
    cerr << #x << " = "; \
    _print(x);           \
    cerr << "\n";
#else
#define debcon(x)
#endif
template <typename T>
void _print(T const &c) {
    cerr << "{ ";
    for (auto it = c.begin(); it != c.end(); it++) {
        it != --c.end() ? cerr << *it << ", " : cerr << *it;
    }
    cerr << "}";
}

// constants
const int mod = 1e9 + 7;
const int N = 1e5 + 10, M = N;
const double PI = 3.1415926535897932384626;

/**
 * @brief-
 *         Given T test cases for which -
 *         Given an Array of size n & q queries on it.
 *         Each Query is a range L to R, we need to find the gcd of the array excluding the range L,R (both inclusive)
 *
 * @approach -
 *      Brute Force -  Calculate the gcd from 1 to l-1 index & the calculate the gcd from r+1 to n index
 *                     Time Complexity - O(T*(N + Q*(N))) = O(T*N*Q) ~ O(N^3)
 *
 *
 *
 */

// Global variables
vi graph[N];
bool vis[N];

// classes & functions
void bruteForce() {
    int n, q;
    cin >> n >> q;
    vi vec(n + 10);
    vec[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> vec[i];
    }
    int n, q;
    cin >> n >> q;
    vi vec(n + 10);
    vec[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> vec[i];
    }
    while (q--) {
        int n = vec.size();
        int l, r;
        cin >> l >> r;
        int gc = 0;
        for (int i = 1; i <= l - 1; ++i) {
            gc = __gcd(gc, vec[i]);
        }
        for (int i = r + 1; i <= n; ++i) {
            gc = __gcd(gc, vec[i]);
        }
        cout << gc << "\n";
    }
}
void optimal() {
}

int main() {
    // Start time
    auto start = chrono::steady_clock::now();

    // fast io
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

// Input, Output & error messages inside text files
#ifndef ONLINE_JUDGE
    freopen("/home/falconcodes/prathamesh/programming/input.txt", "r", stdin);
    freopen("/home/falconcodes/prathamesh/programming/output.txt", "w", stdout);
    freopen("/home/falconcodes/prathamesh/programming/err.txt", "w", stderr);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        bruteForce();
    }

// Calculating Runtime
#ifndef ONLINE_JUDGE
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "[Finished in " << setprecision(3) << chrono::duration<double, milli>(diff).count() << " ms]\n";
#endif
    return 0;
}

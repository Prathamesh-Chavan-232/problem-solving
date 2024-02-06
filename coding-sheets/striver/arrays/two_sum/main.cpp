#include <bits/stdc++.h>
using namespace std;

// Shortening syntax
#define ll long long
#define fo(i, n) for (ll i = 0; i < n; ++i)
#define Fo(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? ++i : --i)
#define pb push_back
#define mp make_pair
#define pqb priority_queue<int>
#define pqs priority_queue<int, vector<int>, greater<int>>
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define foreach(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define formap(m) for (auto [key, value] : m)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Typdefs for containers
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

// Container input tools
void inVec(vector<int> &v)
{
    string s;
    getline(cin, s);
    int num = 0, sign = 1;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '[' || s[i] == ']')
            continue;
        if (s[i] == '-')
            sign = -1;
        else if (s[i] == ',')
            v.push_back(num), num = 0;
        else
        {
            num = num * 10 + (s[i] - '0');
            num *= sign;
            sign = 1;
        }
    }
    v.push_back(num);
}

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

// STL vector / set (of any type) debugger
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
    foreach (it, c)
    {
        cerr << *it << ", ";
    }
    cerr << "}";
}

// Function definitions
void Add_edge(int v1, int v2);
void dfs(int vertex);

// constants
const int mod = 1000000007;
const int N = 1e5 + 10, M = N;
const double PI = 3.1415926535897932384626;

vpii graph[N]; // For Adjacency List
bool vis[N];

/*
    Link -
    Problem -
    Difficulty -
    topic -
    Status -
    Date -
*/
/*  Approach -
        1) Brute force
            For each index in the array, linearly traverse through the indices after it and check if sum of 2 elements equals target

        2) Better - Two pointer approach
            Sort the array and take 2 pointers start and end and check if nums[start] + nums[end] == target

            if the sum is smaller move start forward (we need a bigger sum)
            if the sum is greater move end backward (we need a smaller sum)

        3) Optimal - hash map
            At start, take an empty hash map
            Iterate through the array and for each iteration,
            1) Check if target - arr[i] exists in the hash map
            2) Add arr[i] to the map, add after checking
               because of the edge case arr[i] == target - arr[i]

        Since a pair always exists when we add arr[i], when we iterate through its pair it will find arr it in the map as target - arr[i]

*/
class Solution
{
public:
    vector<int> twoSum(vector<int> &arr, int target)
    {
        vi res;
        int n = arr.size();
        unordered_map<int, int> hsh;
        for (int i = 0; i < n; i++)
        {
            int x = target - arr[i];
            if (hsh.find(x) != hsh.end())
            {
                res.pb(i);
                res.pb(hsh[x]);
            }
            hsh[arr[i]] = i;
        }
        return res;
    }
};
class Solution2
{
public:
    vector<int> twoSum(vector<int> &arr, int target)
    {
        vi res, nums;
        int n = arr.size();
        nums = arr;
        sort(all(nums));
        int start = 0, end = n - 1, n1, n2;

        while (start < end)
        {
            if (nums[start] + nums[end] == target)
            {
                n1 = nums[start];
                n2 = nums[end];
                break;
            }
            else if (nums[start] + nums[end] < target)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (n1 == arr[i] || n2 == arr[i])
                res.pb(i);
        }
        return res;
    }
};
class Solution1
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    res.push_back(i);
                    res.push_back(j);
                    break;
                }
            }
        }
        return res;
    }
};

void code()
{
    Solution s;
    vi arr;
    inVec(arr);
    int target;
    cin >> target;
    vi res = s.twoSum(arr, target); // store return value
    debcon(res);
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

    code();

// Calculating Runtime
#ifndef ONLINE_JUDGE
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "[Finished in " << setprecision(3) << chrono::duration<double, milli>(diff).count() << " ms]\n";
#endif
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// written random implementation of the API to avoid errors locally
bool isBadVersion(int version)
{
    return (version > 4 && version < 8) ? true : false;
}

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int low = 1, high = n;
        int lastBad = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            bool isBad = isBadVersion(mid);
            if (isBad)
            {
                lastBad = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return lastBad;
    }
};
void solve()
{
}
int main()
{
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:/Prathamesh/Programming/input.txt", "r", stdin);
    freopen("C:/Prathamesh/Programming/output.txt", "w", stdout);
    freopen("C:/Prathamesh/Programming/err.txt", "w", stderr);
#endif
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        solve();
    }
    return 0;
}
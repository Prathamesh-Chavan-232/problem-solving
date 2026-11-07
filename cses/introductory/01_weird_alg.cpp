#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    cout << n << " ";
    while (n != 1)
    {
        if (n % 2)
        {
            n = 3 * n + 1;
        }
        else
        {
            n = n / 2;
        }
        cout << n << " ";
    }
}

int main()
{
    cin.tie(NULL);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        solve();
    }
    return 0;
}

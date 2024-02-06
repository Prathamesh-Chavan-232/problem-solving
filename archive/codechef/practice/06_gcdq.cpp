#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void brute()
{
    int n, q;
    cin >> n >> q;
    int arr[n + 1];
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int gc = 0;
        for (int i = 1; i <= l - 1; ++i)
        {

            gc = __gcd(gc, arr[i]);
        }
        for (int i = r + 1; i <= n; ++i)
        {
            gc = __gcd(gc, arr[i]);
        }
        cout << gc << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:/Prathamesh/Programming/input.txt", "r", stdin);   // input
    freopen("C:/Prathamesh/Programming/output.txt", "w", stdout); // output
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        int arr[n + 1], forward[n + 1], backward[n + 1];
        forward[0] = backward[n + 1] = 0;

        for (int i = 1; i <= n; ++i)
        {
            cin >> arr[i];
        }

        for (int i = 1; i <= n; ++i)
        {
            forward[i] = __gcd(arr[i], forward[i - 1]);
        }
        for (int i = n; i >= 1; i--)
        {
            backward[i] = __gcd(arr[i], backward[i + 1]);
        }

        while (q--)
        {
            int l, r;
            cin >> l >> r;
            int gc = __gcd(forward[l - 1], backward[r + 1]);
            cout << gc << endl;
        }
    }
    return 0;
}

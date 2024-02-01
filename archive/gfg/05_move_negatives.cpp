#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class soln
{

public:
    void brute(vector<int> &v, int n)
    {
        int j = 0;
        for (int i = 0; i < n; ++i)
        {
            if (v[i] < 0)
            {
                if (i != j)
                {
                    swap(v[i], v[j]);
                }
                j++;
            }
        }
    }
    void twoPointer(vector<int> &v, int n)
    {
        int left = 0, right = n - 1;
        while (left < right)
        {
            if (v[left] < 0)
            {
                left++;
            }
            if (v[right] > 0)
            {
                right--;
            }
            else if (v[right] < 0 && v[left] > 0)
            {
                swap(v[left], v[right]);
                left++;
                right--;
            }
        }
    }
    void DNF_alg(vector<int> &v, int n)
    {
        int low = 0, high = n - 1;
        while (low <= high)
        {
            if (v[low] <= 0)
                low++;
            else
                swap(v[low], v[high--]);
        }
    }
    void getData(vector<int> &v, int n)
    {
        for (int i = 0; i < n; ++i)
        {
            cin >> v[i];
        }
    }

    void printArray(vector<int> v, int n)
    {
        for (int i = 0; i < n; ++i)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
};
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
        int n;
        cin >> n;
        soln s;
        vector<int> v(n);
        s.getData(v, n);
        cout << "Before moving\n";
        s.printArray(v, n);
        cout << endl;
        s.twoPointer(v, n);
        cout << "After moving\n";
        s.printArray(v, n);
    }
    return 0;
}
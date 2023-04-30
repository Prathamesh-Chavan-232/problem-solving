#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    int min = *min_element(v.begin(), v.end());
    cout << min << endl;
    int max = *max_element(v.begin(), v.end());
    cout << max << endl;
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << sum << endl;
    int ct = count(v.begin(), v.end(), 4);
    cout << ct << endl;
    auto it = find(v.begin(), v.end(), 10);
    if (it == v.end())
    {
        cout << "Not found!\n";
    }
    else
    {
        cout << *it << endl;
    }
    reverse(v.begin(), v.end());
    for (auto &value : v)
    {
        cout << value << " ";
    }
    cout << endl;
    string s = "Adncw";
    reverse(s.begin(), s.end());
    cout << s <<endl;
    return 0;
}
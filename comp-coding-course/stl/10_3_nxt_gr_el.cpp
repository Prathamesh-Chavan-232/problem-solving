#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> NGE(vector<int> v)
{
    stack<int> st;
    vector<int> nge(v.size());
    for (int i = 0; i < v.size(); ++i)
    {
        while (!st.empty() && v[i] > v[st.top()])
        {
            nge[st.top()] = v[i];
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        nge[st.top()] = -1;
        st.pop();
    }
    return nge;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    vector<int> nge = NGE(v);
    for (auto &value : v)
    {
        cout << value << " ";
    }
    cout << endl;
    for (auto &value : nge)
    {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}
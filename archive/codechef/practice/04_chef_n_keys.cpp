#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class graph
{

private:
    vector<int> *adj_list;

public:
    graph() {}
    graph(int n);
    void Add_edge(int v1, int v2);
    void dfs(int vertex, vector<bool> &vis);
    void chk_keys(vector<bool> &vis);
};
graph::graph(int n)
{
    adj_list = new vector<int>[n];
}
void graph::Add_edge(int v1, int v2)
{
    adj_list[v1].push_back(v2);
}

void graph::dfs(int vertex, vector<bool> &vis)
{
    vis[vertex] = true;

    for (auto &child : adj_list[vertex])
    {
        if (!vis[child])
        {
            dfs(child, vis);
        }
    }
}

void graph::chk_keys(vector<bool> &vis)
{
    bool flag = true;
    int n = vis.size();
    for (int i = 0; i < n; ++i)
    {
        if (vis[i] == false)
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        graph rooms(n);
        vector<bool> vis(n, false);
        for (int i = 0; i < n; ++i)
        {
            int k;
            cin >> k;
            for (int j = 0; j < k; ++j)
            {
                int key;
                cin >> key;
                rooms.Add_edge(i, key);
            }
        }
        rooms.dfs(0, vis);
        rooms.chk_keys(vis);
    }
    return 0;
}
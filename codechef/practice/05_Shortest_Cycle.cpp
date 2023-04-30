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
    void dfs(int vertex, vector<bool> &vis, bool &cycle, int &len);
};
graph::graph(int n)
{
    adj_list = new vector<int>[n];
}
void graph::Add_edge(int v1, int v2)
{
    adj_list[v1].push_back(v2);
    adj_list[v2].push_back(v1);
}

void graph::dfs(int vertex, vector<bool> &vis, bool &cycle, int &len)
{
    vis[vertex] = true;
    len++;
    for (auto &child : adj_list[vertex])
    {
        if (!vis[child])
        {
            dfs(child, vis, cycle, len);
        }
        else // if we are going inside visited node
        {
            cycle = true;
            return;
        }
    }
}
bool dfs(int u, int par, vector<int> adj[], vector<bool> &vis)
{
    vis[u] = true; //marking the current vertex as visited.

    for (auto v : adj[u])
    { //iterating on all the adjacent vertices.
        if (v == par)
            continue;

        //if current vertex is visited, we return true else we call the function recursively to detect the cycle.

        if (vis[v])
            return true;
        if (dfs(v, u, adj, vis))
            return true;
    }
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
    {
        //if vertex is not visited, we call the function to detect cycle.
        if (!visited[i])
        {
            bool cycle = dfs(i, -1, adj, visited);
            if (cycle)
                return true;
        }
    }
    return false;
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int len = 0;
        graph g(n + 1);
        vector<bool> vis(n, false);
        bool cycle = false;
        int v1, v2;
        for (int i = 0; i < m; ++i)
        {
            cin >> v1 >> v2;
            g.Add_edge(v1, v2);
        }
        g.dfs(v1, vis, cycle, len);
        cout << endl;
        if (cycle == true)
        {
            cout << len << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> &ans, int ind, vector<bool> &vis, vector<vector<int>> &adjList)
{
    queue<int> q;
    q.push(ind);
    // now we are going to check all neignpurs of ind, so it is visited,
    vis[ind] = true;
    while (!q.empty())
    {
        int node = q.front();
        ans.push_back(node);
        q.pop();
        for (int neighbor : adjList[node])
        {
            if (!vis[neighbor])
            {
                q.push(neighbor);
                vis[neighbor] = true;
            }
        }
    }
}

int main()
{
    int v, e;
    cin >> v >> e;
    // make yourself adjacency list.
    vector<vector<int>> adjList(v + 1);
    for (int i = 0; i < e; i++)
    {
        int u, w;
        cin >> u;
        cin >> w;
        adjList[u].push_back(w);
        adjList[w].push_back(u);
    }
    vector<bool> vis(v + 1, false);
    vector<int> ans;

    for (int i = 0; i < v; i++)
    {
        if (vis[i] == false)
        {
            // this node is not visisted, apply bfs
            bfs(ans, i, vis, adjList);
        }
    }
    for (int i = 0; i < v; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
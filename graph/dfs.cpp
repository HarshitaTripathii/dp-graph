#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> &ans, int ind, vector<bool> &vis, vector<vector<int>> &adjList)
{
    ans.push_back(ind);
    vis[ind]=true;
    for(int neighbor : adjList[ind]){
        if(!vis[neighbor]){
            dfs(ans, neighbor, vis, adjList);
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
            dfs(ans, i, vis, adjList);
        }
    }
    for (int i = 0; i < v; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
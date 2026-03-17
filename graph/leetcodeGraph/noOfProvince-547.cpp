#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int ind, vector<bool> &vis, vector<vector<int>> &isConnected)
    {
        vis[ind] = true;
        for (int n = 0; n < isConnected.size(); n++)
        {
            if (isConnected[ind][n] == 1 && !vis[n])
            {
                dfs(n, vis, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<bool> vis(n, false);
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                c++;
                dfs(i, vis, isConnected);
            }
        }
        return c;
    }
};
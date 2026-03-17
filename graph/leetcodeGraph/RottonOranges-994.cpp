#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        // source queue
        queue<pair<pair<int, int>, int>> sq;
        // freshCount
        int fc=0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    // push them into q, a multi source bfs
                    sq.push({{i, j}, 0});
                    vis[i][j]=true;
                }
                if(grid[i][j]==1){
                    fc++;
                }
            }
        }
        // bfs
        vector<int>dx={-1, 0, 1, 0};
        vector<int>dy={0, -1, 0, 1};

        int ans=0;

        while(!sq.empty()){
            auto curr= sq.front();
            int t=curr.second;
            int i=curr.first.first;
            int j=curr.first.second;
            sq.pop();
            ans = max(ans, t);
            for(int k=0;k<4;k++){
                int nx=i+dx[k];
                int ny=j+dy[k];

                // for all these neighbors, ake them rot, 
                // by marking them visited, pushing into sq, and updating time with =1

                if(nx<n && ny< m && nx>=0 && ny>=0 && grid[nx][ny]==1 && vis[nx][ny]==false ){
                    vis[nx][ny]=true;
                    sq.push({{nx, ny}, t+1});
                    fc--;
                }
            }

        }

        return (fc==0 ? ans : -1);

    
        // return ans;

    }
};

class Solution {
  public:
    bool dfs(int start, vector<bool>&vis, vector<int>&parent, vector<vector<int>>&adjList){
        
        vis[start]=true;
        for(int neighbor: adjList[start])
        {
            if(!vis[neighbor]){
                parent[neighbor]=start;
                if(dfs(neighbor, vis, parent, adjList)){
                    return true;
                }
            }
            else{
                if(neighbor != parent[start]){
                    return true;
                }
            }
        }
        return false;
    }
    bool bfs(int start, vector<bool>&vis, vector<int>&parent, vector<vector<int>>&adjList){
        queue<int>q;
        q.push(start);
        vis[start]=true;
        parent[start]=-1;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            
            for(int neighbor : adjList[curr])
            {
                if(!vis[neighbor]){
                    q.push(neighbor);
                    vis[neighbor]=true;
                    parent[neighbor]=curr;
                }
                else{
                    if(neighbor== parent[curr]) {
                        continue;
                    }
                    else{
                        //cycle detected
                        return true;
                    }
                    
                }
            }
            
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adjList(V);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int w=edges[i][1];
            adjList[u].push_back(w);
            adjList[w].push_back(u);
        }
        vector<bool>vis(V, false);
        vector<int>parent(V);
        bool ans;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                parent[i]=-1;
                if(dfs(i, vis, parent, adjList)) {
                    return true;
                }
            }
        
    }
    return false;
    }
    
};

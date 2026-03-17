class Solution {
  public:
    bool dfs(int curr, vector<bool>&vis, vector<vector<int>>&adjList, vector<bool>&path){
        vis[curr]=true;
        path[curr]=true;
        for(int neighbor : adjList[curr]){
            if(!vis[neighbor]){
                
                if(dfs(neighbor, vis,  adjList, path)){
                    return true;
                }
            }
            else{
                if(path[neighbor]==true){
                     return true;
                }
               
            }
        }
        path[curr]=false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adjList(V);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int w=edges[i][1];
            adjList[u].push_back(w);
        }
        
        vector<bool>vis(V, false);
        vector<bool>path(V, false);
        vector<int>parent(V);
        bool ans;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                parent[i]=-1;
                if(dfs(i, vis, adjList, path)) {
                    return true;
                }
            }
        
    }
    }
};

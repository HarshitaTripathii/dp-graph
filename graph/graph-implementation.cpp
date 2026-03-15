#include<bits/stdc++.h>
using namespace std;
void greet(string s){
    cout << "Hello" << s << endl;
}
int info();

// adjMat : using vector of pair, where each pairn represent 2 vertices, connected by an edge
// representing an undirected, unweighted graph using an adjacency matrix.
// sc : O(V*V)
vector<vector<int>> graphRepM(int v, int e, vector<pair<int, int>>edges){
  vector<vector<int>> adjMat(v+1, vector<int>(v+1, 0));

  for(auto edge : edges)
  {
    int u= edge.first;
    int w= edge.second;

    adjMat[u][w]=1;
    adjMat[w][u]=1;
  }
  return adjMat;

}

// adj list : list of vectors as rows==vertices are fixed and
//  columns == no. of edges from each vertices, are not fixed
//  sc : O(2*e)
vector<vector<int>> graphRepL(int v, int e, vector<pair<int, int>>edges ){
    vector<vector<int>> adjList(v+1);

    for(int i=0;i<e; i++)
    {
        int u= edges[i].first;
        int w= edges[i].second;
        adjList[u].push_back(w);
        adjList[w].push_back(u);
    }

    return adjList;

}

int main(){
    // code
    // greet("Harshita");


    return 0;
}

int info()
{
    cout << "this tell the basic structure of cpp codes"<< endl;
    return 0;
}

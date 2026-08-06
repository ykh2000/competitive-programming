#include <bits/stdc++.h>
using namespace std;

/**
 * Adjacency List Representation 
 */

 vector<vector<int>> createGraph(int V, vector<vector<int>> & edges){
    std::vector<std::vector<int>> adj(V);
    for(auto &it:edges){ // Add every edge to the adjacency list
        int u =it[0];
        int v = it[1];
        adj[u].push_back(v);
        //since the graph is undirected
        adj[v].push_back(u);
    }
    return adj;
 }



int main()
{
    int V = 3;
    std::vector<std::vector<int>> edges = {{0,1},{0,2},{1,2}};
    vector<vector<int>> adj = createGraph(V, edges);
    cout << "Adjacency List Representation:"<<endl;
    for (int i = 0; i < V; i++) {
        cout<< i << ": ";
        for(int j:adj[i]){
            cout<< j << " ";
        }
        cout<< endl;
    }
    return 0;
}
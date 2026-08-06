 
 #include<vector>
 #include <iostream>
 using namespace std;


 int main() {
    // N - Number of nodes
    // E - Edges
    // E = N-1(always) only for Trees not for graphs 
    int N,E;cin>>N>>E;
    /***
     *  ADJ_LIST LOOKS SOMETHING LIKE - 
     * 
  [
    [],
    [],
    [],
    [],
    []
  ]
     *
     */

    vector<vector<int>> adj_list(N);
    for (int i = 0; i < E; i++) {
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    for (int i = 0; i < N; i++) {
        cout<< i << " -> ";
        for (int neighbour: adj_list[i]) {
            cout<<neighbour<<" ";
        }
        cout<<endl;
    }

     return 0;
 }
 
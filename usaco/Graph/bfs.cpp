#include <bits/stdc++.h>

#define vi vector<int>
#define vll vector<long long>
#define qu  queue<int>
#define vb vector<bool> 
using namespace std;

vector<vi> adj_list(int N, int E){
    vector<vi> graph(N);
    for (int i = 0; i < E; i++) {
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 0; i < N; i++) {
        cout<< i << ":"; 
        for(int neighbour: graph[i]){
            cout<<neighbour <<" ";
        }
        cout<<endl;
    }
    return graph;
}

int bfs(int src, const vector<vi>&graph){
    int N =graph.size();
    queue<int> bfsQ;
    vb visited(N,false);
    int visCnt = 0;
    visited[src] = true;
    bfsQ.push(src);
    while(!bfsQ.empty()){
        int node = bfsQ.front();
        bfsQ.pop();
        visCnt++;
        for(int ne: graph[node]){
            if(!visited[ne]){
                visited[ne] = true;
                bfsQ.push(ne);
            }
        }
    }
    return visCnt;
}


int main() {
   int N,E;cin>>N>>E;
   vector<vi> graph = adj_list(N,E);
   int src;cin>>src;
   int traversalNode = bfs(src,graph);
   cout << traversalNode << endl;
    return 0;
}


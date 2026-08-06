#include <bits/stdc++.h>
#define vi vector<int>
#define vb vector<bool>
#define vll vector<long long>
#define qu queue<int>
using namespace std;

vector<vi> adj_list_un(int N, int E){
    vector<vi> graph(N);
    int u,v;
    for (int i = 0; i < E; i++) {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    return graph;
}

vector<vi> adj_list_di(int N, int E){
    vector<vi> graph(N);
    int u,v;
    for (int i = 0; i < E; i++) {
        graph[u].push_back(v);
    }
    return graph;
}

int bfs(int src, const vector<vi> &graph){
    qu bfsQ;
    vector<bool> visited;
    int visCount = 0;
    visited[src] = true;
    bfsQ.push(src);
    while(!bfsQ.empty()){
        int node = bfsQ.front();
        bfsQ.pop();
        visCount++;
        for(int ne:graph[node]){
            if(!visited[ne]){
                visited[ne] = true;
                bfsQ.push(ne);
            }
        }
    }
    return visCount;
}


int main() {

    int N,E;cin>>N>>E;
    vector<vi> graph = adj_list_un(N,E);
    int src;cin>>src;
    int travNode = bfs(src,graph);
    cout<<travNode<<endl;
    return 0;
}
/**
 * DFS - Implementation
 * 
 */


#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;
const int N = 1e5+9;
vector<int>g(N);
bool visited[N];



void dfs_iter(int start, vector<vi>& graph){
    /**
     ** Visited Boolean Vector**
     * - Initialized with 
     * - graph.size
     * - false marked for visited 
     */
    vector<bool> visited(graph.size(), false);
    // Stack to 
    stack <int> st;
    st.push(start);
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!visited[node]) continue;
        visited[node] = true;
        cout<<node<<" ";
        for(int neighbour:graph[node]){
            if(!visited[neighbour]){
                st.push(neighbour);
            }
        }
    }
}


//5th

void dfs_iter(int start, vector<vi> &graph){
    vector<bool> visited(graph.size(), false);
    stack<int> st;
    st.push(start);
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!visited[node]) continue;
        visited[node] = true;
        cout<<node<<" ";
        for(int neighbour:graph[node]){
            if(!visited[neighbour]){
                st.push(neighbour);
            }
        }
    }
}


//6th time 
void dfs_iter(int start, vector<vi>&graph){
    vector<bool> visited (graph.size(), false);
    stack<int> st;
    st.push(start);
    // Until Stack is empty
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!visited[node]) continue;
        visited[node] = true; cout<<node<<" ";
        for(int neighbour: graph[node]){
            if(!visited[neighbour]){
                st.push(neighbour);
            }
        }
    }
}






void dfs_recursive(int node, const vector<vi>&graph, vector<bool> &visited){
    visited[node] = true;
    cout<<node<<" ";
    for(int neighbour: graph[node]){
        if(!visited[neighbour]){
            dfs_recursive(neighbour, graph, visited);
        }
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N  = 5;
    vector<vi> graph(N);

    //Adjacent List Representation 
    graph[0] = {1, 4};
    graph[1] = {0, 2, 3, 4};
    graph[2] = {1, 3};
    graph[3] = {1, 2, 4};
    graph[4] = {0, 1, 3};

    cout<<"Recursive DFS from 0: ";
    vector<bool>visited(N, false);
    dfs_iter(1, graph);
    cout<<endl;


    return 0;
}
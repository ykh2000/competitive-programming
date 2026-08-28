/** Idea - 
 * 1. Store all the points - in a vector
 * 2. Build an undirected graph
 * 3. Count Connected components using iterative DFS
 * 4. Print Component-1
 */



#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;cin>>n;
    vector<pair<int, int>>points(n);
    for (int i = 0; i < n; i++) {
        cin>>points[i].first>>points[i].second;
    }

    //Build an undirected graph
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if(points[i].first ==  points[j].first || points[i].second ==  points[j].second){
                adj[i].push_back(j);
                adj[j].push_back(i);

            }
        }
    }
    /**
     * Now Look at visited components 
     */
    vector<bool> visited(n,false);
    int components  = 0;
    for (int i = 0; i < n; i++) {
        if(visited[i]) continue;
        components++;
        stack<int>st;
        st.push(i);
        visited[i] = true;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            for(int neighbours:adj[node]){
                if(!visited[neighbours]){
                    visited[neighbours] = true;
                    st.push(neighbours);
                }
            }
         } 
    }
    cout<<components-1<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
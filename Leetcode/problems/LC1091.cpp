/**
 * Whenever a Problem asks for 
 * 1. Shortest Path 
 * 2. Unweighted Graphs/Grid
 * 3. Minimum Number of Steps
 * 
 * we use BFS.
 * BFS mathematical guarantees a Short-Path
 * 
 * 8 Directions - 
 * (-1, -1)   (-1,  0)   (-1, +1)
      ↖         ↑         ↗
  ( 0, -1)  ← (r, c) →  ( 0, +1)
      ↙         ↓         ↘
  (+1, -1)   (+1,  0)   (+1, +1)
 * 

Visual Dry-Run - 

Input Grid:
[
  [0, 1, 0],
  [1, 0, 0],
  [1, 1, 0]
]




 * 
 */


#include <bits/stdc++.h>

#define vi vector<int>
using namespace std;

int bfs(int src, vector<vi>&graph){
    int n = graph.size();
    queue<int> bfsQueue;
    vector<bool> visited(n);
    int visCnt = 0;
    visited[src] = true;
    bfsQueue.push(src);
    while(!bfsQueue.empty()){
        int currNode = bfsQueue.front();
        bfsQueue.pop();
        visCnt++;
        for(auto ne:graph[currNode]){
            if(!visited[ne]){
                visited[ne] = true;
                bfsQueue.push(ne);
            }
        }
    }
    return visCnt;
}

class Solution {
public:

    int ShortestPathBinaryMatrix(vector<vector<int>> &graph){
        int n = graph.size(); 
        if(n==0) return -1;
        if(n==1) return 1; // grid is [[]]
        //check If we have a starting or ending point
        if(graph[0][0] == 1  || graph[n-1][n-1] == 1) return -1;
        const int dr[8] = {-1,-1,0,0,1,1,1};
        const int dc[8] = {-1,0,1,-1,1,-1,0,1};
        //BFS Visited Queue for cell positions 
        queue<pair<int,int>> q;
        q.push({0,0});
        graph[0][0] = 1; // First cell is visited.
        // Every cell tells us if It has been visited or not 
        graph[0][0] = 1;
        while(!q.empty()){
            pair<int,int>curr = q.front();
            int r = q.front().first;
            int c = q.front().second;
            //Distance stored at this cell
            int dist  = graph[r][c];
            if(r == n-1 || c == n-1) return dist;

            //CHECK ALL 8 directions 
            for (int i = 0; i < 8; i++) {
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 && nr<n-1 && nc>=0 && nc<n-1 && graph[nr][nc] == 0){
                    graph[nr][nc] = dist+1; //mark the neighbours distance and stores its distance
                    q.push({nr,nc}); // add the neighbour to the queue to process later
                }
            }

        }
        return -1;


     }

    };






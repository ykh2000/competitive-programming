#include <bits/stdc++.h>
using namespace std;
/**
 * - A queue for BFS
 * - A Result Matrix
 * - Direction Array
 */
   
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix){
    
    
     int rows = matrix.size();
    int cols = matrix[0].size();
    
        queue<pair<int,int>> q;
    vector<vector<int>> dist = matrix;
    vector<pair<int,int>> dir = {
        {-1,0},
        {1,0},
        {0,-1},
        {0,1}
    };
    
    //1. Initiliaze the Queue and mark the unvisited Cells
    /**
     * something like this -
     * [
     * [0,1,1],
     * [1,0,1].
     * [0,0,0]
     * 
     * Queue will become - 
     * Q [(0,0)(1,1),(2,0),(2,1),(2,2)]
     *              AND
     * The Matrix will become - 
     * [
     * [0,-1,-1],
     * [-1,0,-1],
     * [0,0,0]
     * ]
     * We can use -1 and some other value like INT_MIN and INT_MAX
     * ]
     */
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if(matrix[i][j] == 0){
                q.push({i,j});
            }
            else{
                dist[i][j] = -1;
            }
        }
    }

    // 2. MULTI-SOURCE BFS
    while(!q.empty()){
        auto [r,c] = q.front();
        q.pop();
        for(auto [dr,dc]: dir){
            int nr = r+dr;
            int nc = c+dc;
            if(nr < 0 || nr >=rows || nc < 0|| nc >=cols){
                continue;
            }
            if(dist[nr][nc] == -1){
                dist[nr][nc] = dist[r][c]+1;
                q.push({nr,nc});
            }
        }
    }

    return dist;
    }


};

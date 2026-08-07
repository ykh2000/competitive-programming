#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        if(fresh == 0){
            return 0;
        }
        int minutes = 0;
        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};
        //Multi-source BFS
        while(!q.empty()){
            int size = q.size();
            bool rottedThisMin = false;
            while(size--){
                auto [r,c] = q.front();
                q.pop();
                //Visit all 4 neighbours
                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    //If Roting is outside the grid
                    if(nr < 0 || nr >=row || nc < 0 ||nc >= col)
                    continue;
                    //Skip if not a fresj orange
                    if(grid[nr][nc] != 1){
                        continue;
                    }
                    //Rot the fresh Oranges
                    grid[nr][nc] = 2;
                    fresh--;
                    q.push({nr,nc});
                }
            }
            if(!q.empty()) minutes++;
        }
        if(fresh == 0) return minutes;

        return -1;
    }
};
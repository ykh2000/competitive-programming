
/**
 * In-Place marking - No const
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     int numIslands(vector<vector<char>>& grid){
    if(grid.empty() || grid[0].empty()) return 0;
       int rows = (int)grid.size(); //row
       int cols = (int)grid[0].size(); // cols
       int islandCount = 0;
       for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            //If we find an unvisited land cell --> New Island
            if(grid[i][j] == '1'){
                islandCount++;
                dfs(grid, i,j,rows, cols);
            }
        }
       }
       return islandCount++;
     }
private:
     //Directional Array - 
     /**
      * (r-1, c)   ← up     dr[0]=-1, dc[0]= 0
        (r+1, c)   ← down   dr[1]=+1, dc[1]= 0
        (r, c-1)   ← left   dr[2]= 0, dc[2]=-1
        (r, c+1)   ← right  dr[3]= 0, dc[3]=+1
      */
     /**
      * STATIC - ONE COPY SHARED BY ALL INSTANCE
      * CONSTEXPR - EVALUATED AT COMPILE TIME
      * dr[0] is baked into binary as -1 and not looked up at runtime.
      */
     static constexpr int dr[4] = {-1,1,0,0};
     static constexpr int dc[4] = {0,0,-1,1};
     void dfs(vector<vector<char>>&grid, int r, int c, int rows, int cols){
        if(r < 0 || r>= rows || c<0 || c >=cols || grid[r][c] != '1'){
            return;
        }
        //MARK VISITED by sinking the land back to water.
        grid[r][c] = '0';
        for (int k = 0; k < 4; k++) {
            dfs(grid, r+dr[k], c+dc[k], rows, cols);
        }
     }

};
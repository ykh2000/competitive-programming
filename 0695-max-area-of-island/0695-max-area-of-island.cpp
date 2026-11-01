/***
 * WHY LEETCODE GIVE YOU -
 * VECTOR<VECTOR<INT>>  AND NOT RAW ARRAYS LIKE 
 * void function(int grid [50][50]) {
 * 
 * };
 * Raw 2D array can not carry their own size. Vectors can
 * Raw arrays can't be returned or copied.
 * 
 * 
 * RAW int g[50][50] --> INSIDE A FUNCTION GOES ON THE STACK 
 * A DFS CAN CAUSE STACK OVERFLOW.
 * vector<vector<int>> g(50, vector<int>(50)); --> GOES ON THE HEAP.
 * 
 * 
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //const & is for readonly inputs, but we are modifiying the grid
    //So., No const

    int maxAreaOfIsland(vector<vector<int>> &grid){
        //reject empty grid before touching grid[0].
        if(grid.empty() || grid[0].empty()) return 0;
        int rows = grid.size(); //row count 
        int cols = grid[0].size();//col count 
        int maxArea = 0; // runnning max
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if(grid[i][j] == 1){
                    const int area = dfs(grid,i,j, rows, cols);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }

private:
        // PASS BY REFERENCE (&) : RECURSION MEANS  EVERY CALL SEES THE SAME GRID
        // MUTATION (SINKING) SURVIVES ACROSS ALL FRAMES.
        /**
         * WITH & - ALL FRAMES SHARE THE SAME GRID. SINKING WORKS
         * WITHOUT & - EVERY CALL COPIES THE WHOLE GRID --> MASSIVE TIME COST AND 
         * SINKING DOES NOT STICK --> INFINITE RECURSION --> STACK OVERFLOW.
         */
    int dfs(vector<vector<int>> &grid, int r, int c, int rows, int cols){
        /**
         * DIRECTIONAL ARRAYS -  4 NEIGHBOURS IN (dr[k], dc[k]) Order.
         * K=0 -> DOWN (+1,0)
         * K=1 -> UP(-1,0)
         * K=2 -> RIGHT (0,+1)
         * K=3 -> LEFT (0,-1);
         */
        static const int dr[4] = {+1,-1,0,0};
        static const int dc[4] = {0,0,-1,+1};
        //Out of bound check 
        const bool oob = (r<0 || r>=rows || c<0 || c >= cols);
        if(oob || grid[r][c] == 0){
                return 0;
            }
        //sink
        // Future DFS treats if(grid[i][j] == 1) as WATER
        grid[r][c] = 0; //mark it visited.
        int total = 1;
        for(int k = 0;k<4;k++){
            total+=dfs(grid, r+dr[k], c+dc[k], rows ,cols);
        }
        return total;

    }
    
};
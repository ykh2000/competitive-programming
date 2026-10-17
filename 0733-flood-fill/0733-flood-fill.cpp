/**
We must recolor only cells that have the same original color as the starting cell.
*
**/



class Solution {
public:
/// Params - grid to modify, (r,c) - current cell , oldcolor - color to be recolored , color - new color
    void dfs(vector<vector<int>>&image, int r, int c, int oldColor, int color){
        int m = image.size(); // Number of rows.
        int n = image[0].size(); // Number of cols in the first rows.
        if( r < 0 || r>=m || c < 0 || c> n || image[r][c] != oldColor){
            return;
        }
        else{
            image[r][c] = color; // else give it the new color
            dfs(image, r-1, c, oldColor, color);
            dfs(image, r+1, c , oldColor, color);
            dfs(image, r, c-1, oldColor, color);
            dfs(image, r, c+1, oldColor, color);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        if (oldColor == color){ // cell number is same
            return image;
        }
        dfs(image, sr, sc, oldColor, color);
        return image;

    }
};
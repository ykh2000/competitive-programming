class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int perimeter = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) continue;

                perimeter += 4;

                // Count each shared side exactly once
                if (r + 1 < m && grid[r + 1][c] == 1)
                    perimeter -= 2;

                if (c + 1 < n && grid[r][c + 1] == 1)
                    perimeter -= 2;
            }
        }

        return perimeter;
    }
};
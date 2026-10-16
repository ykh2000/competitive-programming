class Solution {
public:
    int m, n;
    int perimeter = 0;

    vector<vector<int>> visited;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    void dfs(int r, int c, vector<vector<int>>& grid) {
        visited[r][c] = 1;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // Side lies outside the grid
            if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                perimeter++;
            }
            // Side borders water
            else if (grid[nr][nc] == 0) {
                perimeter++;
            }
            // Visit connected land
            else if (!visited[nr][nc]) {
                dfs(nr, nc, grid);
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        visited.assign(m, vector<int>(n, 0));

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1 && !visited[r][c]) {
                    dfs(r, c, grid);
                    return perimeter; // Original problem has one island
                }
            }
        }

        return 0;
    }
};
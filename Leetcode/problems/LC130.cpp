
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int rows, cols;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    void dfs(vector<vector<char>>& board, int startRow, int startCol) {

        stack<pair<int,int>> st;

        // Start from one boundary O
        st.push({startRow, startCol});

        while (!st.empty()) {

            pair<int,int> current = st.top();
            st.pop();

            int row = current.first;
            int col = current.second;

            // Already visited?
            if (board[row][col] == '#')
                continue;

            // Mark this O as safe
            board[row][col] = '#';

            // Check the 4 neighbours
            for (int i = 0; i < 4; i++) {

                int newRow = row + dr[i];
                int newCol = col + dc[i];

                // Is neighbour inside the board?
                if (newRow >= 0 && newRow < rows &&
                    newCol >= 0 && newCol < cols &&
                    board[newRow][newCol] == 'O') {

                    st.push({newRow, newCol});
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {

        if (board.empty())
            return;

        rows = board.size();
        cols = board[0].size();

        // Left & Right boundaries
        for (int row = 0; row < rows; row++) {

            if (board[row][0] == 'O')
                dfs(board, row, 0);

            if (board[row][cols - 1] == 'O')
                dfs(board, row, cols - 1);
        }

        // Top & Bottom boundaries
        for (int col = 0; col < cols; col++) {

            if (board[0][col] == 'O')
                dfs(board, 0, col);

            if (board[rows - 1][col] == 'O')
                dfs(board, rows - 1, col);
        }

        // Flip surrounded regions
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {

                if (board[row][col] == 'O')
                    board[row][col] = 'X';

                else if (board[row][col] == '#')
                    board[row][col] = 'O';
            }
        }
    }
};
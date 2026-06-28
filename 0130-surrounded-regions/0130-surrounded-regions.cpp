class Solution {
public:
    int rows, cols;
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    // DFS to mark all 'O's connected to the border as visited (safe)
    void dfs(int row, int col, vector<vector<bool>>& visited, vector<vector<char>>& board) {
        bool outOfBounds = (row < 0 || col < 0 || row >= rows || col >= cols);
        if (outOfBounds || visited[row][col] || board[row][col] == 'X') return;

        visited[row][col] = true;

        for (int k = 0; k < 4; k++) {
            int newRow = row + dirs[k][0];
            int newCol = col + dirs[k][1];
            dfs(newRow, newCol, visited, board);
        }
    }

    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        // Step 1: DFS from all border 'O's to mark safe regions
        for (int row = 0; row < rows; row++) {
            if (board[row][0] == 'O' && !visited[row][0])
                dfs(row, 0, visited, board);

            if (board[row][cols - 1] == 'O' && !visited[row][cols - 1])
                dfs(row, cols - 1, visited, board);
        }

        for (int col = 0; col < cols; col++) {
            if (board[0][col] == 'O' && !visited[0][col])
                dfs(0, col, visited, board);

            if (board[rows - 1][col] == 'O' && !visited[rows - 1][col])
                dfs(rows - 1, col, visited, board);
        }

        // Step 2: Flip all unvisited 'O's — they are fully surrounded
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (board[row][col] == 'O' && !visited[row][col])
                    board[row][col] = 'X';
            }
        }
    }
};
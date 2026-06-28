class Solution {
public:
    int rows, cols;
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    // DFS to mark all land cells connected to the border as visited (safe)
    void dfs(int row, int col, vector<vector<bool>>& visited, vector<vector<int>>& grid) {
        bool outOfBounds = (row < 0 || col < 0 || row >= rows || col >= cols);
        if (outOfBounds || visited[row][col] || grid[row][col] == 0) return;

        visited[row][col] = true;

        for (int k = 0; k < 4; k++) {
            int newRow = row + dirs[k][0];
            int newCol = col + dirs[k][1];
            dfs(newRow, newCol, visited, grid);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        // Step 1: DFS from all border land cells to mark safe regions
        for (int row = 0; row < rows; row++) {
            if (grid[row][0] == 1 && !visited[row][0])
                dfs(row, 0, visited, grid);

            if (grid[row][cols - 1] == 1 && !visited[row][cols - 1])
                dfs(row, cols - 1, visited, grid);
        }

        for (int col = 0; col < cols; col++) {
            if (grid[0][col] == 1 && !visited[0][col])
                dfs(0, col, visited, grid);

            if (grid[rows - 1][col] == 1 && !visited[rows - 1][col])
                dfs(rows - 1, col, visited, grid);
        }

        // Step 2: Count all unvisited land cells — they are fully enclosed
        int count = 0;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 1 && !visited[row][col])
                    count++;
            }
        }
        return count;
    }
};
class Solution {
public:

    int rows, cols;
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    void dfs(int row, int col, vector<vector<bool>>& visited, vector<vector<char>>& grid) {
        bool outOfBound = (row < 0 || row >= rows || col < 0 || col >= cols);
        if(outOfBound || grid[row][col] == '0' || visited[row][col]) return;

        visited[row][col] = true;

        for (int k = 0; k < 4; k++) {
            int newRow = row + dirs[k][0];
            int newCol = col + dirs[k][1];
            dfs(newRow, newCol, visited, grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool> (cols, false));

        int islandCount = 0;
        for(int row = 0 ; row < rows ; row++){
            for(int col = 0 ; col < cols ; col++) {

                if(grid[row][col] == '1' && !visited[row][col]){
                    islandCount++;
                    dfs(row, col, visited, grid);
                }
            }
        }
        return islandCount;
    }
};
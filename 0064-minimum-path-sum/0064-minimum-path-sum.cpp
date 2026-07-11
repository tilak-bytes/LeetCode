class Solution {
private:
    int solveRec(int i, int j, vector<vector<int>>& grid) {
        if(i == 0 && j == 0) return grid[i][j];
        if(i < 0 || j < 0) return INT_MAX - 200;     //Subtracted 200 to prevent overflow as max value can be 200.

        int up = grid[i][j] + solveRec(i - 1, j, grid);
        int left = grid[i][j] + solveRec(i, j - 1, grid);

        return min(up, left);
    }

    //Another way to prevent overflow in recursive solution is:
    int solveRec2(int i, int j, vector<vector<int>>& grid) {
        if(i == 0 && j == 0) return grid[i][j];
        if(i < 0 || j < 0) return INT_MAX;

        int up = (i > 0) ? solveRec2(i - 1, j, grid) : INT_MAX;
        int left = (j > 0) ? solveRec2(i, j - 1, grid) : INT_MAX;

        return grid[i][j] + min(up, left);
    }

    int solveMem(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(i == 0 && j == 0) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];

        int up = (i > 0) ? solveMem(i - 1, j, grid, dp) : INT_MAX;
        int left = (j > 0) ? solveMem(i, j - 1, grid, dp) : INT_MAX;

        return dp[i][j] = grid[i][j] + min(up, left);
    }

    int solveTab(int m, int n, vector<vector<int>>& grid) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                    continue;
                }

                int up = (i > 0) ? dp[i - 1][j] : INT_MAX;
                int left = (j > 0) ? dp[i][j - 1] : INT_MAX;

                dp[i][j] = grid[i][j] + min(up, left);
            }
        }

        return dp[m - 1][n - 1];
    }

    int solveSO(int m, int n, vector<vector<int>>& grid) {
        vector<int> prev(n, 0);

        for(int i = 0; i < m; i++) {
            vector<int> curr(n, 0);
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) {
                    curr[j] = grid[i][j];
                    continue;
                }

                int up = (i > 0) ? prev[j] : INT_MAX;
                int left = (j > 0) ? curr[j - 1] : INT_MAX;

                curr[j] = grid[i][j] + min(up, left);
            }
            prev = curr;
        }

        return prev[n - 1];
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m  = grid.size();
        int n = grid[0].size();

        // return solveRec(m - 1, n - 1, grid);
        //return solveRec2(m - 1, n - 1, grid);

        //vector<vector<int>> dp(m, vector<int>(n, -1));
        //return solveMem(m - 1, n - 1, grid, dp);

        //return solveTab(m, n, grid);

        return solveSO(m, n, grid);
    }
};
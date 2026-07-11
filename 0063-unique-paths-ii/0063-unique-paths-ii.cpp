class Solution {
private:
    int solveRec(int m, int n, vector<vector<int>>& obstacleGrid) {
        if(m < 0 || n < 0) return 0;
        if(obstacleGrid[m][n] == 1) return 0;
        if(m == 0 && n == 0) return 1;

        int up = solveRec(m - 1, n, obstacleGrid);
        int left = solveRec(m, n - 1, obstacleGrid);

        return up + left;
    }

    int solveTab(int m, int n, vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }
                if(i == 0 && j == 0) {
                    dp[i][j] = 1;
                    continue;
                }

                int up = (i > 0 ) ? dp[i - 1][j] : 0;
                int left = (j > 0 ) ? dp[i][j - 1] : 0;

                dp[i][j] = up + left;
            }
        }
        return dp[m - 1][n - 1];
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        //return solveRec(m - 1, n - 1, obstacleGrid);

        return solveTab(m, n, obstacleGrid); 
    }
};
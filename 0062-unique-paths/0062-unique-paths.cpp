class Solution {
private:
    int solveRec(int m, int n) {
        if(m == 0 && n == 0) return 1;

        if(m < 0 || n < 0) return 0;

        int up = solveRec(m - 1, n);
        int left = solveRec(m, n - 1);

        return up + left;
    }

    int solveMem(int m, int n, vector<vector<int>>& dp) {

        if(m == 0 && n == 0) return 1;

        if(m < 0 || n < 0) return 0;

        if(dp[m][n] != -1) return dp[m][n];

        int up = solveMem(m - 1, n, dp);
        int left = solveMem(m, n - 1, dp);

        return dp[m][n] = up + left;
    }

    int solveTab(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(i == 0 && j == 0) {
                    dp[0][0] = 1;
                    continue;
                }
                int up = (i > 0) ? dp[i - 1][j] : 0;
                int left = (j > 0) ? dp[i][j - 1] : 0;

                dp[i][j] = up + left;
            }
        }
        return dp[m - 1][n - 1];
    }

public:
    int uniquePaths(int m, int n) {
        //return solveRec(m - 1, n - 1);

        //vector<vector<int>> dp(m, vector<int>(n, -1));
        //return solveMem(m - 1, n - 1, dp);

        return solveTab(m, n);
    }
};
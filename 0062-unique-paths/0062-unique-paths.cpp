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

public:
    int uniquePaths(int m, int n) {
        //return solveRec(m - 1, n - 1);

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solveMem(m - 1, n - 1, dp);
    }
};
class Solution {
private:
    int solveRec(int i, int j, int m, vector<vector<int>>& triangle) {
        if(i == m - 1) return triangle[i][j];

        int down = triangle[i][j] + solveRec(i + 1, j, m, triangle);
        int right = triangle[i][j] + solveRec(i + 1, j + 1, m, triangle);

        return min (down, right);
    }

    int solveMem(int i, int j, int m, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if(i == m - 1) return triangle[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int down = triangle[i][j] + solveMem(i + 1, j, m, triangle, dp);
        int right = triangle[i][j] + solveMem(i + 1, j + 1, m, triangle, dp);

        return dp[i][j] = min (down, right);
    }

    int solveTab(int m, vector<vector<int>>& triangle) {
        vector<vector<int>> dp(m, vector<int>(m, -1));

        for(int i = 0 ; i < m ; i++) 
            dp[m - 1][i] = triangle[m - 1][i];

        for(int i = m - 2 ; i >= 0 ; i--) {
            for(int j = i ; j >= 0 ; j--) {
                int down = dp[i + 1][j];
                int right = dp[i + 1][j + 1];

                dp[i][j] = triangle[i][j] + min(down, right);
            }
        }
        return dp[0][0];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        //return solveRec(0, 0, m, triangle);

        //vector<vector<int>> dp(m, vector<int>(m, -1));
        //return solveMem(0, 0, m, triangle, dp);

        return solveTab(m, triangle);
    }
};
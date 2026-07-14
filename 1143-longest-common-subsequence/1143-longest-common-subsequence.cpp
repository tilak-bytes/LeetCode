class Solution {
private:
    int solveRec(int i, int j, string& text1, string& text2) {
        if(i < 0 || j < 0) return 0;

        if(text1[i] == text2[j]) return 1 + solveRec(i - 1, j - 1, text1, text2);

        return max(solveRec(i - 1, j, text1, text2), solveRec(i, j - 1, text1, text2));
    }

    int solveMem(int i, int j, string& text1, string& text2, vector<vector<int>>& dp) {
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(text1[i] == text2[j]) return dp[i][j] = 1 + solveMem(i - 1, j - 1, text1, text2, dp);

        return dp[i][j] = max(solveMem(i - 1, j, text1, text2, dp), solveMem(i, j - 1, text1, text2, dp));
    }

    // Shifting of index by 1.
    int solveMem2(int i, int j, string& text1, string& text2, vector<vector<int>>& dp) {
        if(i == 0 || j == 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(text1[i - 1] == text2[j - 1]) return dp[i][j] = 1 + solveMem2(i - 1, j - 1, text1, text2, dp);

        return dp[i][j] = max(solveMem2(i - 1, j, text1, text2, dp), solveMem2(i, j - 1, text1, text2, dp));
    }

    int solveTab(int n, int m, string& text1, string& text2) {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(int i = 1 ; i <= n ; i++) {
            for(int j = 1 ; j <= m ; j++) {
                if(text1[i - 1] == text2[j - 1]) 
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                else 
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }

    int solveSO (int n, int m, string& text1, string& text2) {
        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);

        for(int i = 1 ; i <= n ; i++) {
            for(int j = 1 ; j <= m ; j++) {
                if(text1[i - 1] == text2[j - 1]) 
                    curr[j] = 1 + prev[j - 1];

                else 
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return prev[m];
        
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        // return solveRec(n - 1, m - 1, text1, text2);

        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        // return solveMem2(n, m, text1, text2, dp);

        // return solveTab(n, m, text1, text2);

        return solveSO(n, m, text1, text2);
    }
};
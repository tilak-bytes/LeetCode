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

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        // return solveRec(n - 1, m - 1, text1, text2);

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solveMem(n - 1, m - 1, text1, text2, dp);
    }
};
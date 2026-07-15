class Solution {
public:
    // Recursive (Brute Force)
    int solveRec(string &s1, string &s2, int i, int j) {
        if (i == 0 || j == 0) return 0;
        
        if (s1[i-1] == s2[j-1])
            return 1 + solveRec(s1, s2, i-1, j-1);
        else
            return max(solveRec(s1, s2, i-1, j), solveRec(s1, s2, i, j-1));
    }
    
    // Memoized (Top-Down)
    int solveMem(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
        if (i == 0 || j == 0) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        if (s1[i-1] == s2[j-1])
            return dp[i][j] = 1 + solveMem(s1, s2, i-1, j-1, dp);
        else
            return dp[i][j] = max(solveMem(s1, s2, i-1, j, dp), 
                                   solveMem(s1, s2, i, j-1, dp));
    }
    
    // Tabulation (Bottom-Up)
    int solveTab(string &s1, string &s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n][m];
    }
    
    // Space-Optimized
    int solveSO(string &s1, string &s2) {
        int n = s1.size(), m = s2.size();
        vector<int> prev(m+1, 0), curr(m+1, 0);
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i-1] == s2[j-1])
                    curr[j] = 1 + prev[j-1];
                else
                    curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        
        return prev[m];
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        // int lcs = solveRec(word1, word2, n, m);
        
        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // int lcs = solveMem(word1, word2, n, m, dp);
        
        // int lcs = solveTab(word1, word2);
        
        int lcs = solveSO(word1, word2);
        
        return n + m - 2 * lcs;
    }
};
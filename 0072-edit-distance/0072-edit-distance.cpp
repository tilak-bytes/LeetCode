class Solution {
public:
    // 1. Recursive (Brute Force)
    int solveRec(string &s1, string &s2, int i, int j) {
        if (i == 0) return j; // insert remaining j characters
        if (j == 0) return i; // delete remaining i characters
        
        if (s1[i-1] == s2[j-1])
            return solveRec(s1, s2, i-1, j-1); // no operation needed
        
        int insertOp = solveRec(s1, s2, i, j-1);     // insert
        int deleteOp = solveRec(s1, s2, i-1, j);     // delete
        int replaceOp = solveRec(s1, s2, i-1, j-1);  // replace
        
        return 1 + min({insertOp, deleteOp, replaceOp});
    }
    
    // 2. Memoized (Top-Down)
    int solveMem(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
        if (i == 0) return j;
        if (j == 0) return i;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        if (s1[i-1] == s2[j-1])
            return dp[i][j] = solveMem(s1, s2, i-1, j-1, dp);
        
        int insertOp = solveMem(s1, s2, i, j-1, dp);
        int deleteOp = solveMem(s1, s2, i-1, j, dp);
        int replaceOp = solveMem(s1, s2, i-1, j-1, dp);
        
        return dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
    }
    
    // 3. Tabulation (Bottom-Up)
    int solveTab(string &s1, string &s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        // base cases
        for (int i = 0; i <= n; i++) dp[i][0] = i; // delete all i chars
        for (int j = 0; j <= m; j++) dp[0][j] = j; // insert all j chars
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
            }
        }
        
        return dp[n][m];
    }
    
    // 4. Space-Optimized
    int solveSO(string &s1, string &s2) {
        int n = s1.size(), m = s2.size();
        vector<int> prev(m+1, 0), curr(m+1, 0);
        
        // base case for row 0
        for (int j = 0; j <= m; j++) prev[j] = j;
        
        for (int i = 1; i <= n; i++) {
            curr[0] = i; // base case for this row (deleting i chars)
            for (int j = 1; j <= m; j++) {
                if (s1[i-1] == s2[j-1])
                    curr[j] = prev[j-1];
                else
                    curr[j] = 1 + min({curr[j-1], prev[j], prev[j-1]});
            }
            prev = curr;
        }
        
        return prev[m];
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        
        // return solveRec(word1, word2, n, m);
        
        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // return solveMem(word1, word2, n, m, dp);
        
        return solveTab(word1, word2);
        
        // return solveSO(word1, word2);
    }
};
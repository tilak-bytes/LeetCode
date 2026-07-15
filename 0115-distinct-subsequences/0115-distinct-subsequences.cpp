class Solution {
public:
    // Recursive
    int solveRec(string &s, string &t, int i, int j) {
        if (j == 0) return 1;      // empty t is always a subsequence
        if (i == 0) return 0;      // t not empty but s is empty
        
        if (s[i-1] == t[j-1])
            return solveRec(s, t, i-1, j-1) + solveRec(s, t, i-1, j);
        else
            return solveRec(s, t, i-1, j);
    }
    
    // Memoized (Top-Down)
    int solveMem(string &s, string &t, int i, int j, vector<vector<long long>> &dp) {
        if (j == 0) return 1;
        if (i == 0) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        if (s[i-1] == t[j-1])
            return dp[i][j] = solveMem(s, t, i-1, j-1, dp) + solveMem(s, t, i-1, j, dp);
        else
            return dp[i][j] = solveMem(s, t, i-1, j, dp);
    }
    
    // Tabulation (Bottom-Up)
    int solveTab(string &s, string &t) {
        int n = s.size(), m = t.size();
        vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0));
        
        // base case: dp[i][0] = 1 for all i
        for (int i = 0; i <= n; i++) dp[i][0] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][m];
    }
    
    // Space-Optimized
    int solveSO(string &s, string &t) {
        int n = s.size(), m = t.size();
        vector<long long> dp(m+1, 0);
        dp[0] = 1; // base case
        
        for (int i = 1; i <= n; i++) {
            // traverse j from right to left so dp[j-1] is still previous row's value
            for (int j = m; j >= 1; j--) {
                if (s[i-1] == t[j-1])
                    dp[j] = dp[j] + dp[j-1];
                // else dp[j] remains same (carried from previous row)
            }
        }
        
        return dp[m];
    }
    
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        // return solveRec(s, t, n, m);
        
        vector<vector<long long>> dp(n+1, vector<long long>(m+1, -1));
        return solveMem(s, t, n, m, dp);
        
        // return solveTab(s, t);
        
        return solveSO(s, t);
    }
};
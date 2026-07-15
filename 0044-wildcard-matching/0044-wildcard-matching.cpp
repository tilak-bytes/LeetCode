class Solution {
public:
    // Recursive
    bool solveRec(string &s, string &p, int i, int j) {
        // i = length of s considered, j = length of p considered
        
        // both strings exhausted -> match
        if (i == 0 && j == 0) return true;
        
        // s exhausted but p still has characters -> only matches if all remaining are '*'
        if (j == 0) return false; // p exhausted but s isn't -> no match
        
        if (i == 0) {
            // check if p[0..j) are all '*'
            for (int k = 0; k < j; k++) {
                if (p[k] != '*') return false;
            }
            return true;
        }
        
        if (p[j-1] == '*') {
            // '*' matches empty sequence OR matches s[i-1] and continues
            return solveRec(s, p, i-1, j) || solveRec(s, p, i, j-1);
        }
        else if (p[j-1] == '?' || s[i-1] == p[j-1]) {
            return solveRec(s, p, i-1, j-1);
        }
        else {
            return false;
        }
    }
    
    // Memoized (Top-Down)
    int solveMem(string &s, string &p, int i, int j, vector<vector<int>> &dp) {
        // using int dp: -1 = not computed, 0 = false, 1 = true
        
        if (i == 0 && j == 0) return 1;
        
        if (j == 0) return 0;
        
        if (i == 0) {
            for (int k = 0; k < j; k++) {
                if (p[k] != '*') return 0;
            }
            return 1;
        }
        
        if (dp[i][j] != -1) return dp[i][j];
        
        if (p[j-1] == '*') {
            return dp[i][j] = (solveMem(s, p, i-1, j, dp) || solveMem(s, p, i, j-1, dp));
        }
        else if (p[j-1] == '?' || s[i-1] == p[j-1]) {
            return dp[i][j] = solveMem(s, p, i-1, j-1, dp);
        }
        else {
            return dp[i][j] = 0;
        }
    }
    
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();

        // return solveRec(s, p, n, m);
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solveMem(s, p, n, m, dp) == 1;
    }
};
class Solution {
private:
    int solveRec(int i, int j, string& s1, string& s2) {
        if(i < 0 || j < 0) return 0;

        if(s1[i] == s2[j])
            return 1 + solveRec(i - 1, j - 1, s1, s2);
        
        return max(solveRec(i - 1, j, s1, s2), solveRec(i, j - 1, s1, s2));
    }

    int solveMem(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j])
            return dp[i][j] = 1 + solveMem(i - 1, j - 1, s1, s2, dp);

        return dp[i][j] = max(solveMem(i - 1, j, s1, s2, dp), solveMem(i, j - 1, s1, s2, dp));
    }

public:
    int longestPalindromeSubseq(string s1) {
        string s2 = s1;
        reverse(s2.begin(), s2.end());

        int n = s1.length();
        // return solveRec(n - 1, n -1, s1, s2);

        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solveMem(n - 1, n - 1, s1, s2, dp);
    }
};
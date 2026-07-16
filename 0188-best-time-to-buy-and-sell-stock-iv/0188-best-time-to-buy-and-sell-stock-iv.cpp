class Solution {
public:

    // ---------- 1. Pure Recursion ----------
    int solveRec(int index, int buy, int cap, vector<int>& prices) {
        int n = prices.size();
        if (index == n || cap == 0) return 0;

        int profit = 0;
        if (buy) {
            profit = max(-prices[index] + solveRec(index + 1, 0, cap, prices),
                          0 + solveRec(index + 1, 1, cap, prices));
        } else {
            profit = max(prices[index] + solveRec(index + 1, 1, cap - 1, prices),
                          0 + solveRec(index + 1, 0, cap, prices));
        }
        return profit;
    }

    // ---------- 2. Memoization ----------
    int solveMem(int index, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        int n = prices.size();
        if (index == n || cap == 0) return 0;

        if (dp[index][buy][cap] != -1) return dp[index][buy][cap];

        int profit = 0;
        if (buy) {
            profit = max(-prices[index] + solveMem(index + 1, 0, cap, prices, dp),
                          0 + solveMem(index + 1, 1, cap, prices, dp));
        } else {
            profit = max(prices[index] + solveMem(index + 1, 1, cap - 1, prices, dp),
                          0 + solveMem(index + 1, 0, cap, prices, dp));
        }

        return dp[index][buy][cap] = profit;
    }

    // ---------- 3. Tabulation ----------
    int solveTab(int k, vector<int>& prices) {
        int n = prices.size();
        // dp[index][buy][cap], index: 0..n, buy: 0..1, cap: 0..k
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= k; cap++) {  // cap == 0 row stays 0 (base case)
                    int profit;
                    if (buy) {
                        profit = max(-prices[index] + dp[index + 1][0][cap],
                                      0 + dp[index + 1][1][cap]);
                    } else {
                        profit = max(prices[index] + dp[index + 1][1][cap - 1],
                                      0 + dp[index + 1][0][cap]);
                    }
                    dp[index][buy][cap] = profit;
                }
            }
        }
        return dp[0][1][k];
    }

    // ---------- 4. Space Optimized ----------
    int solveSO(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> ahead(2, vector<int>(k + 1, 0)), curr(2, vector<int>(k + 1, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= k; cap++) {
                    int profit;
                    if (buy) {
                        profit = max(-prices[index] + ahead[0][cap],
                                      0 + ahead[1][cap]);
                    } else {
                        profit = max(prices[index] + ahead[1][cap - 1],
                                      0 + ahead[0][cap]);
                    }
                    curr[buy][cap] = profit;
                }
            }
            ahead = curr;
        }
        return ahead[1][k];
    }

    // ---------- Main entry point ----------
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;

        // 1. Recursion
        // return solveRec(0, 1, k, prices);

        // 2. Memoization
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        // return solveMem(0, 1, k, prices, dp);

        // 3. Tabulation
        return solveTab(k, prices);

        // 4. Space Optimized
        // return solveSO(k, prices);
    }
};
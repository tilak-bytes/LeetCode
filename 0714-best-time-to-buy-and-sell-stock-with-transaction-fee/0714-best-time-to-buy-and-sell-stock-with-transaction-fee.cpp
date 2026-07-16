class Solution {
public:

    // ---------- 1. Pure Recursion ----------
    int solveRec(int index, int buy, vector<int>& prices, int fee) {
        int n = prices.size();
        if (index == n) return 0;

        int profit = 0;
        if (buy) {
            profit = max(-prices[index] + solveRec(index + 1, 0, prices, fee),
                          0 + solveRec(index + 1, 1, prices, fee));
        } else {
            // subtract fee when a transaction completes (on sell)
            profit = max(prices[index] - fee + solveRec(index + 1, 1, prices, fee),
                          0 + solveRec(index + 1, 0, prices, fee));
        }
        return profit;
    }

    // ---------- 2. Memoization ----------
    int solveMem(int index, int buy, vector<int>& prices, int fee, vector<vector<int>>& dp) {
        int n = prices.size();
        if (index == n) return 0;

        if (dp[index][buy] != -1) return dp[index][buy];

        int profit = 0;
        if (buy) {
            profit = max(-prices[index] + solveMem(index + 1, 0, prices, fee, dp),
                          0 + solveMem(index + 1, 1, prices, fee, dp));
        } else {
            profit = max(prices[index] - fee + solveMem(index + 1, 1, prices, fee, dp),
                          0 + solveMem(index + 1, 0, prices, fee, dp));
        }

        return dp[index][buy] = profit;
    }

    // ---------- 3. Tabulation ----------
    int solveTab(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit;
                if (buy) {
                    profit = max(-prices[index] + dp[index + 1][0],
                                  0 + dp[index + 1][1]);
                } else {
                    profit = max(prices[index] - fee + dp[index + 1][1],
                                  0 + dp[index + 1][0]);
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }

    // ---------- 4. Space Optimized ----------
    int solveSO(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> ahead(2, 0), curr(2, 0);

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit;
                if (buy) {
                    profit = max(-prices[index] + ahead[0],
                                  0 + ahead[1]);
                } else {
                    profit = max(prices[index] - fee + ahead[1],
                                  0 + ahead[0]);
                }
                curr[buy] = profit;
            }
            ahead = curr;
        }
        return ahead[1];
    }

    // ---------- Main entry point ----------
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n <= 1) return 0;

        // 1. Recursion
        // return solveRec(0, 1, prices, fee);

        // 2. Memoization
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return solveMem(0, 1, prices, fee, dp);

        // 3. Tabulation
        // return solveTab(prices, fee);

        // 4. Space Optimized
        return solveSO(prices, fee);
    }
};
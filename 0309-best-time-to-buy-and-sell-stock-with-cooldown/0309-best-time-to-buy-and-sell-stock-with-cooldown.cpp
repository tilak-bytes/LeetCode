class Solution {
public:

    // ---------- 1. Pure Recursion ----------
    int solveRec(int index, int buy, vector<int>& prices) {
        int n = prices.size();
        if (index >= n) return 0;

        int profit = 0;
        if (buy) {
            profit = max(-prices[index] + solveRec(index + 1, 0, prices),
                          0 + solveRec(index + 1, 1, prices));
        } else {
            // after selling, next buy is only allowed from index+2 (1 day cooldown)
            profit = max(prices[index] + solveRec(index + 2, 1, prices),
                          0 + solveRec(index + 1, 0, prices));
        }
        return profit;
    }

    // ---------- 2. Memoization ----------
    int solveMem(int index, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        int n = prices.size();
        if (index >= n) return 0;

        if (dp[index][buy] != -1) return dp[index][buy];

        int profit = 0;
        if (buy) {
            profit = max(-prices[index] + solveMem(index + 1, 0, prices, dp),
                          0 + solveMem(index + 1, 1, prices, dp));
        } else {
            profit = max(prices[index] + solveMem(index + 2, 1, prices, dp),
                          0 + solveMem(index + 1, 0, prices, dp));
        }

        return dp[index][buy] = profit;
    }

    // ---------- 3. Tabulation ----------
    int solveTab(vector<int>& prices) {
        int n = prices.size();
        // need index up to n+1 because of the index+2 jump, so size n+2
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {     // We can omit this for loop as well.
                int profit;
                if (buy) {
                    profit = max(-prices[index] + dp[index + 1][0],
                                  0 + dp[index + 1][1]);
                } else {
                    profit = max(prices[index] + dp[index + 2][1],
                                  0 + dp[index + 1][0]);
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }

    // ---------- 4. Space Optimized ----------
    int solveSO(vector<int>& prices) {
        int n = prices.size();
        // need two "future" rows now: index+1 (ahead1) and index+2 (ahead2)
        vector<int> ahead2(2, 0), ahead1(2, 0), curr(2, 0);

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit;
                if (buy) {
                    profit = max(-prices[index] + ahead1[0],
                                  0 + ahead1[1]);
                } else {
                    profit = max(prices[index] + ahead2[1],
                                  0 + ahead1[0]);
                }
                curr[buy] = profit;
            }
            ahead2 = ahead1;
            ahead1 = curr;
        }
        return ahead1[1];
    }

    // ---------- Main entry point ----------
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        // 1. Recursion 
        // return solveRec(0, 1, prices);

        // 2. Memoization
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return solveMem(0, 1, prices, dp);

        // 3. Tabulation
        // return solveTab(prices);

        // 4. Space Optimized
        return solveSO(prices);
    }
};
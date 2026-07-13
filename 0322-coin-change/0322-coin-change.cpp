class Solution {
private:
    int solveRec(vector<int>& coins, int amount) {
        if (amount == 0) return 0;

        int minCoins = INT_MAX;

        for (int i = 0; i < coins.size(); i++) {
            if(amount - coins[i] >= 0) {
                int res = solveRec(coins, amount - coins[i]);
                if (res != INT_MAX) {
                    minCoins = min(minCoins, res + 1);
                }
            }
        }
        return minCoins;
    }

    int solveMem(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0) return 0;

        if (dp[amount] != -1) return dp[amount];

        int minCoins = INT_MAX;

        for (int i = 0; i < coins.size(); i++) {
            if (amount - coins[i] >= 0) {
                int res = solveMem(coins, amount - coins[i], dp);
                if (res != INT_MAX) {
                    minCoins = min(minCoins, res + 1);
                }
            }
        }
        return dp[amount] = minCoins;
    }

    int solveTab(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int amt = 1; amt <= amount; amt++) {
            for (int i = 0; i < coins.size(); i++) {
                if (amt - coins[i] >= 0 && dp[amt - coins[i]] != INT_MAX) {
                    dp[amt] = min(dp[amt], dp[amt - coins[i]] + 1);
                }
            }
        }
        return dp[amount];
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        // int ans = solveRec(coins, amount);
        // return (ans == INT_MAX) ? -1 : ans;

        // vector<int> dp(amount + 1, -1);
        // int ans = solveMem(coins, amount, dp);
        // return (ans == INT_MAX) ? -1 : ans;

        int ans = solveTab(coins, amount);
        return (ans == INT_MAX) ? -1 : ans;
    }
};
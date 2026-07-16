class Solution {
public:

    int solveMem (int index, int buy, vector<int>& prices, vector<vector<int>> &dp) {
        if (index == prices.size()) return 0;

        if (dp[index][buy] != -1) return dp[index][buy];

        int profit = 0;
        if(buy) {
            profit = max (- prices[index] + solveMem(index+1, 0, prices, dp), 0 + solveMem(index + 1, 1, prices, dp));
        }
        else {
            profit = max ( prices[index] + solveMem(index+1, 1, prices, dp), 0 + solveMem(index + 1, 0, prices, dp));
        }

        return dp[index][buy] = profit;
    }

    int solveTab (vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        int profit;
        for(int i = n - 1 ; i >= 0 ; i--) {
            for(int buy = 0; buy <= 1 ; buy++){
                if(buy) {
                    profit = max (- prices[i] + dp[i+ 1][0], 0 + dp[i + 1][1]);
                }
                else {
                    profit = max ( prices[i] + dp[i + 1][1], 0 + dp[i + 1][0]);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }

    int maxProfit(vector<int>& prices) {

        // vector<vector<int> > dp(prices.size(), vector<int> (2, -1));
        // return solveMem(0, 1, prices, dp);

        return solveTab(prices); 
    }
};
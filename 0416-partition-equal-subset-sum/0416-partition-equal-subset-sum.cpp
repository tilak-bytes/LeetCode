class Solution {
public:
    // ---------- Recursive ----------
    bool solveRec(int index, vector<int>& arr, int sum) {
        if(sum == 0) return true;
        if(index < 0) return false;

        bool notTake = solveRec(index - 1, arr, sum);
        bool take = false;
        if(arr[index] <= sum) {
            take = solveRec(index - 1, arr, sum - arr[index]);
        }
        return take || notTake;
    }

    // ---------- Memoization ----------
    bool solveMem(int index, vector<int>& arr, int sum, vector<vector<int>>& dp) {
        if(sum == 0) return true;
        if(index < 0) return false;

        if(dp[index][sum] != -1) return dp[index][sum];

        bool notTake = solveMem(index - 1, arr, sum, dp);
        bool take = false;
        if(arr[index] <= sum) {
            take = solveMem(index - 1, arr, sum - arr[index], dp);
        }

        return dp[index][sum] = (take || notTake);
    }

    // ---------- Tabulation ----------
    bool solveTab(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        for(int i = 0; i < n; i++)
            dp[i][0] = true;

        if(arr[0] <= sum)
            dp[0][arr[0]] = true;

        for(int index = 1; index < n; index++) {
            for(int target = 1; target <= sum; target++) {
                bool notTake = dp[index - 1][target];
                bool take = false;
                if(arr[index] <= target) {
                    take = dp[index - 1][target - arr[index]];
                }
                dp[index][target] = take || notTake;
            }
        }

        return dp[n - 1][sum];
    }

    // ---------- Space Optimized ----------
    bool solveSO(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<bool> prev(sum + 1, false);

        prev[0] = true;
        if(arr[0] <= sum)
            prev[arr[0]] = true;

        for(int index = 1; index < n; index++) {
            vector<bool> curr(sum + 1, false);
            curr[0] = true;

            for(int target = 1; target <= sum; target++) {
                bool notTake = prev[target];
                bool take = false;
                if(arr[index] <= target) {
                    take = prev[target - arr[index]];
                }
                curr[target] = take || notTake;
            }

            prev = curr;
        }

        return prev[sum];
    }

    // ---------- Main function ----------
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int x : nums) totalSum += x;

        // odd total sum can never be split into two equal halves
        if(totalSum % 2 != 0) return false;

        int target = totalSum / 2;
        int n = nums.size();

        // return solveRec(n - 1, nums, target);

        // vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        // return solveMem(n - 1, nums, target, dp);

        // return solveTab(nums, target);

        return solveSO(nums, target);
    }
};
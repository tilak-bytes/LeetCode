class Solution {

private:
    int solveRec(int idx, vector<int>& nums) {
        if(idx == 0) return nums[0];
        if(idx < 0) return 0;

        int pick = nums[idx] + solveRec(idx - 2, nums);
        int notPick = 0 + solveRec(idx - 1, nums);

        return max(pick, notPick);
    }

    int solveMem(int idx, vector<int>& nums, vector<int>& dp) {
        if(idx < 0) return 0;

        if(dp[idx] != -1) return dp[idx];

        int pick = nums[idx] + solveMem(idx - 2, nums, dp);
        int notPick = 0 + solveMem(idx - 1, nums, dp);

        dp[idx] = max(pick, notPick);
        return dp[idx];
    }

    int solveTab(int idx, vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = nums[0];

        for(int i = 1 ; i < n ; i++) {

            int pick = nums[i];
            if(i > 1) pick += dp[i - 2];
            int notPick = 0 + dp[i - 1];

            dp[i] = max(pick, notPick);
        }
        return dp[n - 1];
    }

    int solveSO(int idx, vector<int>& nums) {
        int n = nums.size();
        int prev = 0;
        int curr = nums[0];

        for(int i = 1 ; i < n ; i++) {

            int pick = nums[i];
            if(i > 1) pick += prev;
            int notPick = 0 + curr;

            int next = max(pick, notPick);
            prev = curr;
            curr = next;
        }
        return curr;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        //return solveRec(n-1, nums);

        // vector<int> dp(n, -1);
        // dp[0] = nums[0];
        // return solveMem(n - 1, nums, dp);

        //return solveTab(0, nums);

        return solveSO(0, nums);
    }
};
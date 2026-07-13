class Solution {
private:
    int solveRec(vector<int>& nums, int idx, int sum) {
        if (idx == nums.size()) 
            return (sum == 0) ? 1 : 0;

        int include = solveRec(nums, idx + 1, sum - nums[idx]);

        int exclude = solveRec(nums, idx + 1, sum);

        return include + exclude;
    }

    int solveMem(vector<int>& nums, int index, int sum, vector<vector<int>>& dp) {
        if(index == nums.size()) return (sum == 0) ? 1 : 0;

        if(dp[index][sum] != -1) return dp[index][sum];

        int include = 0;
        if (sum - nums[index] >= 0) {
            include = solveMem(nums, index + 1, sum - nums[index], dp);
        }

        int exclude = solveMem(nums, index + 1, sum, dp);

        return dp[index][sum] = include + exclude;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int S = 0;
        for(int i = 0 ; i < nums.size() ; i++) S += nums[i];

        if(abs(target) > S) return 0;
        if((S + target) % 2 != 0) return 0;

        int sum = (S + target) / 2;
        //return solveRec(nums, 0, sum);

        vector<vector<int>> dp(nums.size(), vector<int>(sum + 1, -1));
        return solveMem(nums, 0, sum, dp);
    }
};
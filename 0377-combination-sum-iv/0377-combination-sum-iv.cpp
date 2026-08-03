class Solution {
    int recur(int remaining, vector<int>& nums, unordered_map<int,int>& memo) {
        if(remaining == 0) return 1;
        if(remaining < 0) return 0;
        
        if(memo.count(remaining)) return memo[remaining];
        
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            count += recur(remaining - nums[i], nums, memo);
        }
        
        return memo[remaining] = count;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        unordered_map<int,int> memo;
        return recur(target, nums, memo);
    }
};
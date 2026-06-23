class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> exists;

        for(int i = 0 ; i < nums.size() ; i++) {
            int compli = target - nums[i];
            if(exists.count(compli)) {
                return {exists[compli], i};
            }
            exists[nums[i]] = i;
        }
        return {};
    }
};
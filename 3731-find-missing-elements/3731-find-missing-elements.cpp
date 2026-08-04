class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int start = nums[0];
        vector<int> ans;

        for(int i = 0 ; i < n ; i++) {
            if(nums[i] != start) {
                ans.push_back(start);
                i--;
            }
            start++;
        }
        return ans;
    }
};
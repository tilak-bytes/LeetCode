class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int k = 0;

        for(int& num : nums)
            if(num != nums[k]) nums[++k] = num;

        return k + 1;
    }
};
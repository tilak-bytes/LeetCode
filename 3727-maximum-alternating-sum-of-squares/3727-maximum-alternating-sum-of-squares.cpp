class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        for (int &x : nums) x = abs(x);

        sort(nums.begin(), nums.end());

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long sq = 1LL * nums[i] * nums[i];
            
            sum += (i < n / 2) ? -sq : sq;
        }
        return sum;
    }
};
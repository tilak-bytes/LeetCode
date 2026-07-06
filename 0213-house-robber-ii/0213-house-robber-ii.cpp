class Solution {
public:

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

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> temp1, temp2;

        for(int i = 0 ; i < n ; i++) {
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n - 1) temp2.push_back(nums[i]);
        }

        return max(solveSO(0, temp1), solveSO(0, temp2));
    }
};
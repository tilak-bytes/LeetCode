class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> s;

        for(auto num : nums) s.insert(num);

        int maxi = 1;
        for(auto it : s){
            int left = it-1;
            int count = 1;
            while(s.find(left) != s.end()) {
                s.erase(left);
                left = left - 1;
                count++;
            }
            int right = it + 1;
            while(s.find(right) != s.end()) {
                s.erase(right);
                right = right + 1;
                count++;
            }
            maxi = max(maxi, count);
        }
        return maxi;
    }
};
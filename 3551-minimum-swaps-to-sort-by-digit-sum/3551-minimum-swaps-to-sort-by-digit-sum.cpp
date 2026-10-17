class Solution {
    int digitSum(int x) {
        int sum = 0;

        while (x) {
            sum += x % 10;
            x /= 10; 
        }
        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), swaps = 0;

        // sorted order: digit sum ascending, tie me value ascending
        vector<int> target(nums);
        sort(target.begin(), target.end(), [&](int a, int b) {
            
            int da = digitSum(a), db = digitSum(b);
            return da != db ? da < db : a < b;
        });

        unordered_map<int, int> idxOf;
        for (int i = 0; i < n; i++) idxOf[nums[i]] = i;

        for (int i = 0; i < n; i++) {
            int want = target[i];
            int cur = nums[i];

            if (want == cur) continue;

            int j = idxOf[want];       // want abhi kahan pada hai
            swap(nums[i], nums[j]);

            idxOf[want] = i;
            idxOf[cur] = j;

            swaps++;
        }
        return swaps;
    }
};
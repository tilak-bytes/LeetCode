class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        int i = 0;
        while(i < n){
            int x = nums[i] - 1;
            if(nums[i] <= n && nums[i] > 0 && nums[i] != nums[nums[i]-1]){
                int temp = nums[i];
                nums[i] = nums[x];
                nums[x] = temp;
            }
            else i++;
        }
        for( i = 0; i < n; i++){
            if(i+1 != nums[i]) return i+1;
        }
        return n+1;
    }
}
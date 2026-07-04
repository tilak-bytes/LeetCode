class Solution {
public:
    int climbStairs(int n) {
        int prev = 0;
        int curr = 1;

        for(int i = 0 ; i < n ; i++) {
            int newCurr = prev + curr;
            prev = curr;
            curr = newCurr;
        }
        return curr;
    }
};
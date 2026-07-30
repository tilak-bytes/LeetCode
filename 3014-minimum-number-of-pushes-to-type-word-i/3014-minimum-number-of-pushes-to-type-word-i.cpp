class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int factor = 1;
        int ans = 0;

        while(n > 0) {
            if(n >= 8) {
                ans += 8 * factor;
            }
            else{
                ans += n * factor;
                break;
            }
            factor += 1;
            n -= 8;
        }
        return ans;
    }
};
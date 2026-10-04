class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        int setCount = 0;
        for(int i = 0 ; i <= 30 ; i++) {
            if(n & (1 << i)) setCount++;
        }
        return (setCount == 1);
    }
};
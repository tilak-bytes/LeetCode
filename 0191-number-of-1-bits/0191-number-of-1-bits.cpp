class Solution {
public:

    int getSetBits(int n) {
        int count = 0;
        for(int i = 0 ; i < 31 ; i++) 
            if(n & (1 << i)) count++;
        
        return count;
    }

    int hammingWeight(int n) {
        return getSetBits(n);
    }
};
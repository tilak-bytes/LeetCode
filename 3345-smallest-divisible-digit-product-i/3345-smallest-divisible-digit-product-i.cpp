class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i = 0 ; i < 10 ; i++) {
            int prod = 1;
            int num = n + i;
            while(num) {
                int rem = num % 10;
                prod *= rem;
                num /= 10;
            }
            if(prod % t == 0) return n + i;
        }
        return 0;
    }
};
class Solution {
public:
    double getPow(double x, long long n) {
        double factor = x;
        double power = 1.0;

        while(n) {
            if(n & 1) power *= factor;
            factor *= factor;
            n = n >> 1;
        }
        return power;
    }

    double myPow(double x, int n) {
        long long N = n;
        if(N < 0) {
            x = 1 / x;
            N = -N;
        }
        return getPow(x, N);
    }
};
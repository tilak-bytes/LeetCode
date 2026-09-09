class Solution {
public:
    long long countCommas(long long n) {
        long long total = 0;
        long long x = 1000;

        while( x <= n) {
            total += n - x + 1;
            x *= 1000;
        }
        return total;
    }
};

// Time Complexity:  O(log_1000(n))  -> at most 5 iterations for n <= 1e15,
//                   so effectively O(1) for the given constraints.
// Space Complexity: O(1)
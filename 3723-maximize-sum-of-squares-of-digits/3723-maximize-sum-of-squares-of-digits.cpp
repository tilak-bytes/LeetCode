class Solution {
private:
    bool buildNumber(int length, int remainingSum, int pos, string& result) {
        // Prune: sum went negative, or remaining digits can't reach it even with all 9s
        if (remainingSum < 0 || remainingSum > 9 * (length - pos)) return false;

        // All positions filled; the check above guarantees remainingSum == 0
        if (pos == length) return true;

        for (int digit = 9; digit >= 0; digit--) {
            result[pos] = '0' + digit;

            if (buildNumber(length, remainingSum - digit, pos + 1, result))
                return true;  // Largest valid number found, stop early
        }
        // No digit works at this position, backtrack
        return false;
    }

public:
    string maxSumOfSquares(int num, int sum) {
        // Pre-allocate the string so digits can be written in place
        string result(num, '0');
        return buildNumber(num, sum, 0, result) ? result : "";
    }
};
class Solution {
private:
    pair<int, int> expand(const string& s, int left, int right) {
        while (left >= 0 && right < (int)s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return {left + 1, right - left - 1};
    }

public:
    string longestPalindrome(string s) {
        int bestStart = 0, bestLen = 0;

        for (int i = 0; i < (int)s.size(); i++) {
            auto [oddStart, oddLen] = expand(s, i, i);
            auto [evenStart, evenLen] = expand(s, i, i + 1);

            if (oddLen > bestLen) {
                bestStart = oddStart;
                bestLen = oddLen;
            }
            if (evenLen > bestLen) {
                bestStart = evenStart;
                bestLen = evenLen;
            }
        }
        return s.substr(bestStart, bestLen);
    }
};
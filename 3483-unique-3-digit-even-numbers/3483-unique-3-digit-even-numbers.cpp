class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_set<int> seen;

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(i == j) continue;

                for(int k = 0 ; k < n ; k++) {
                    if(i ==  k || j == k) continue;

                    if(digits[i] != 0 && digits[k] % 2 == 0)
                        seen.insert(digits[i] * 100 + digits[j] * 10 + digits[k]);
                }
            }
        }
        return seen.size();
    }
};
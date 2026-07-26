class Solution {
public:

    void generateAll(int n, char last, string comb, vector<string>& ans) {
        if(n == 0) {
            ans.push_back(comb);
            return;
        }

        if(last != '0') {
            generateAll(n - 1, '0', comb + '0', ans);
        }
        generateAll(n - 1, '1', comb + '1', ans);
    }

    vector<string> validStrings(int n) {
        vector<string> ans;
        generateAll(n, '1', "", ans);
        return ans;
    }
};
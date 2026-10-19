class Solution {
private:
    void getAll(int digits, int curr, int n, int k, vector<int>& combi, vector<vector<int>>& ans) {
        if(digits == k){
            ans.push_back(combi);
            return;
        }

        for(int i = curr; i <= n; i++) {
            combi.push_back(i);
            getAll(digits + 1, i + 1, n, k, combi, ans);
            combi.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> combi;
        getAll(0, 1, n, k, combi, ans);
        return ans;
    }
};
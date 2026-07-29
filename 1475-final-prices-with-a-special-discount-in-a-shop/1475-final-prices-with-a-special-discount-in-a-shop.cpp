class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();

        stack<int> s;
        vector<int> ans(n, 0);

        for(int i = n - 1 ; i >= 0 ; i--) {
            while(!s.empty() && prices[s.top()] > prices[i]){
                s.pop();
            }
            ans[i] = !s.empty() ? prices[i] - prices[s.top()] : prices[i];
            s.push(i);
        }
        return ans;
    }
};
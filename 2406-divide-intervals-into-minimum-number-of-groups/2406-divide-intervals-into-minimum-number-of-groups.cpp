class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> st(n), en(n);

        for (int i = 0; i < n; i++) {
            st[i] = intervals[i][0];
            en[i] = intervals[i][1];
        }
        sort(st.begin(), st.end());
        sort(en.begin(), en.end());

        int groups = 0, ans = 0;
        int i = 0, j = 0;
        while(i < n && j < n) {
            if(st[i] <= en[j]) {
                groups++;
                ans = max(ans, groups);
                i++;
            }
            else {
                groups--;
                j++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<pair<int, int>> vec;

        for(auto it : intervals) {
            vec.push_back({it[0], 0});
            vec.push_back({it[1], 1});
        }

        sort(vec.begin(), vec.end());

        int groups = 0, maxGroups = 0;
        for(auto it : vec) {
            if(it.second == 0) {
                groups++;
                maxGroups = max(maxGroups, groups);
            }
            else groups--;
        }
        return maxGroups;
    }
};
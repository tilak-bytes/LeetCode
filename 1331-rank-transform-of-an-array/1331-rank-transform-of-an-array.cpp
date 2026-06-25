class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = arr.size();
        for(int i = 0 ; i < n ; i++) pq.push(arr[i]);

        unordered_map<int, int> mp;
        int rank = 1;
        
        while(!pq.empty()) {
            int val = pq.top();
            pq.pop();

            if(mp.find(val) != mp.end()) continue;
            mp[val] = rank++;
        }

        vector<int> ans;
        for(int i = 0 ; i < n ; i++) ans.push_back(mp[arr[i]]);

        return ans;
    }
};
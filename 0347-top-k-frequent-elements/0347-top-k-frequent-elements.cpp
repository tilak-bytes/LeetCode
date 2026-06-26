class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for(auto num : nums) freq[num]++;

        priority_queue<pair<int, int> >pq;
        for(auto [key, val] : freq) pq.push({val, key});

        vector<int> result;
        while(result.size() < k){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};
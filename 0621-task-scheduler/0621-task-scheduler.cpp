class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for(auto task : tasks) mp[task]++;

        priority_queue<int> pq;
        for(auto freq : mp) pq.push(freq.second);

        int time = 0;
        while(!pq.empty()){
            vector<int> temp;
            int cycleSize = n + 1;

            for (int i = 0 ; i < cycleSize ; i++) {
                if(!pq.empty()){
                    temp.push_back(pq.top());
                    pq.pop();
                }
            }
            for(auto x : temp) 
                if(x - 1 > 0) pq.push(x - 1);
            
            time += (pq.empty()) ? temp.size() : cycleSize;
        }
        return time;
    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // build adjacency list {nextNode, cost}
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto time : times) {
            adj[time[0]].push_back({time[1], time[2]});
        }

        // initialize distances to infinity, src = 0
        vector<int> dist(n + 1, INT_MAX);
        dist[0] = 0;
        dist[k] = 0;

        // min heap {cost, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while(!pq.empty()) {
            auto [dis, node] = pq.top();
            pq.pop();

            if(dis > dist[node]) continue;  // stale entry, skip

            for(auto [nextNode, nextDis] : adj[node]) {
                if(dis + nextDis < dist[nextNode]) {
                    dist[nextNode] = dis + nextDis;
                    pq.push({dis + nextDis, nextNode});
                }
            }
        }

        // find the maximum distance among all nodes (skip index 0)
        int ans = -1;
        for(auto dis : dist) ans = max(ans, dis);
        return ans == INT_MAX ? -1 : ans;
    }
};
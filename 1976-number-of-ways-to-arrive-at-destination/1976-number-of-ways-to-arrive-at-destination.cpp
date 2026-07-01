class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9 + 7;

        // build adjacency list {nextNode, cost}
        vector<vector<pair<int, int>>> adj(n);
        for(auto road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        // dist = shortest distance, ways = number of ways to reach that distance
        vector<long long> dist(n, LLONG_MAX);     // long long to avoid overflow in addition
        vector<long long> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;

        // min heap {cost, node}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, 
                        greater<pair<long long, int>>> pq;
        pq.push({0, 0});

        while(!pq.empty()) {
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(dis > dist[node]) continue;  // stale entry, skip

            for(auto it : adj[node]) {
                int nextNode      = it.first;
                long long nextDis = it.second;

                // found shorter path → update dist, reset ways
                if(dis + nextDis < dist[nextNode]) {
                    dist[nextNode] = dis + nextDis;
                    ways[nextNode] = ways[node];
                    pq.push({dis + nextDis, nextNode});
                }
                // found equal path → add ways
                else if(dis + nextDis == dist[nextNode]) {
                    ways[nextNode] = (ways[nextNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};
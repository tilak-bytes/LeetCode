class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int f = flights.size();
        vector<vector<pair<int, int>>> adj(n);

        // build adjacency list
        for(int i = 0 ; i < f ; i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            adj[u].push_back({v, w});
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // queue stores {stops used, {node, cost so far}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        while(!q.empty()) {
            int stops = q.front().first;
            int node  = q.front().second.first;
            int cost  = q.front().second.second;
            q.pop();

            if(stops > k) continue;  // exceeded stop limit, skip

            for(auto neighbor : adj[node]) {
                int nextNode = neighbor.first;
                int nextCost = neighbor.second;

                if(cost + nextCost < dist[nextNode]) {
                    dist[nextNode] = cost + nextCost;
                    q.push({stops + 1, {nextNode, dist[nextNode]}});  // stops+1 when moving ahead
                }
            }
        }

        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};
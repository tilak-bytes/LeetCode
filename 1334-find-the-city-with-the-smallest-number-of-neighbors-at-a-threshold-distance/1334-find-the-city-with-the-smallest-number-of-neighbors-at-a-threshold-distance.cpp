class Solution {
  public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        int ansCity = -1;
        int minCount = INT_MAX;

        for (int src = 0; src < n; src++) {
            vector<int> dist(n, INT_MAX);
            priority_queue<pair<int,int>,
                           vector<pair<int,int>>,
                           greater<>> pq;

            dist[src] = 0;
            pq.push({0, src});

            while (!pq.empty()) {
                auto [currDist, curr] = pq.top();
                pq.pop();

                if (currDist > dist[curr]) continue;

                for (auto &[neighbor, weight] : adj[curr]) {
                    int newDist = currDist + weight;
                    
                    if (newDist < dist[neighbor]) {
                        dist[neighbor] = newDist;
                        pq.push({newDist, neighbor});
                    }
                }
            }

            int count = 0;
            for (int j = 0; j < n; j++) {
                if (j != src && dist[j] <= distanceThreshold) count++;
            }

            if (count <= minCount) {   // tie par bada index
                minCount = count;
                ansCity = src;
            }
        }
        return ansCity;
    }
};
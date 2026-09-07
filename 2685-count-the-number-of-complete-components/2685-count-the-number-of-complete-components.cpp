class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, int& nodes, long long& edges) {
        visited[node] = true;
        nodes++;
        edges += adj[node].size();

        for(auto nbr : adj[node]) {
            if(!visited[nbr]) dfs(nbr, adj, visited, nodes, edges);
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int E = edges.size();
        vector<vector<int>> adj(n);
        for(int i = 0 ; i < E ; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int completeComponents = 0;

        for(int i = 0 ; i < n ; i++) {
            if(!visited[i]) {
                int nodes = 0;
                long long edgeCount = 0;
                dfs(i, adj, visited, nodes, edgeCount);

                edgeCount /= 2; // each edge counted twice
                long long needed = (long long)nodes * (nodes - 1) / 2;

                if(edgeCount == needed) completeComponents++;
            }
        }
        return completeComponents;
    }
};
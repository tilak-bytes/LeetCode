class Solution {
public:

    bool dfs(int node, int nodeColor, vector<int>& color, vector<vector<int>>& graph) {
        color[node] = nodeColor;

        for (int neighbor : graph[node]) {

            if (color[neighbor] == -1) {
                bool isValid = dfs(neighbor, 1 - nodeColor, color, graph);
                if (!isValid) return false;
                } 
                else if (color[neighbor] == nodeColor) return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, -1);

        for (int src = 0; src < n; src++) {

            if (color[src] == -1) {
                bool isValid = dfs(src, 0, color, graph);
                if (!isValid) return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> revAdj(n);
        vector<int> indegree(n, 0);

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < graph[i].size() ; j++) {
                int u = i;
                int v = graph[i][j];

                revAdj[v].push_back(u);
                indegree[u]++;
            }
        }
        queue<int> q;
        for(int i = 0 ; i < n ; i++) 
            if(indegree[i] == 0) q.push(i);

        vector<int> result;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            result.push_back(node);

            for(auto neighbor : revAdj[node]){
                indegree[neighbor]--;
                if(indegree[neighbor] == 0) q.push(neighbor);
            }
        }

        sort(result.begin(), result.end());
        return result;
    }
};
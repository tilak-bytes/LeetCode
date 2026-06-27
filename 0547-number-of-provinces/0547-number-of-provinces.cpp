class Solution {
public:

    void dfsHelper(int node, vector<vector<int> >& adj, vector<bool>& visited) {
        visited[node] = true;

        for(auto neighbor : adj[node]){
            if(!visited[neighbor])
                dfsHelper(neighbor, adj, visited);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++){
                if(i != j && isConnected[i][j] == 1)
                    adj[i].push_back(j);
            }
        }

        vector<bool> visited(n, false);
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                count++;
                dfsHelper(i, adj, visited);
            }
        }
        return count;
    }
};
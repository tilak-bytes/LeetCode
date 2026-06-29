class Solution {
public:

    bool hasCycle(int node, vector<int>& state, vector<vector<int>>& adj) {
        state[node] = 1;

        for(auto neighbor : adj[node]){
            if(state[neighbor] == 1) return true;

            if(state[neighbor] == 0)
                if(hasCycle(neighbor, state, adj) == true) return true;
        }
        state[node] = 2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();

        vector<vector<int>> adj(numCourses);

        for(int i = 0 ; i < n ; i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[v].push_back(u);        // v → u
        }

        vector<int> state(numCourses, 0);

        for(int i = 0 ; i < numCourses ; i++)
            if(state[i] == 0)
                if(hasCycle(i, state, adj)) return false;

        return true;  
    }
};
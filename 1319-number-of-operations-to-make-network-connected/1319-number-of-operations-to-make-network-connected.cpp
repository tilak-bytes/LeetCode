class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    // path compression
    int findUPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    // union by size
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return; // redundant edge

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if (m < n - 1) return -1; // not enough edges

        DisjointSet ds(n);
        for (auto& it : connections) ds.unionBySize(it[0], it[1]);

        int cntComponents = 0;
        for (int i = 0; i < n; i++)
            if (ds.findUPar(i) == i) cntComponents++;

        return cntComponents - 1;
    }
};
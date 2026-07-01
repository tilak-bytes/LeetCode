class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> efforts(n, vector<int>(m, INT_MAX));
        efforts[0][0] = 0;

        int dirs[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

        priority_queue<pair<int,pair<int,int>>, 
                       vector<pair<int,pair<int,int>>>, 
                       greater<pair<int,pair<int,int>>>> pq;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            int eff = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            if (i == n-1 && j == m-1) return eff;

            if (eff > efforts[i][j]) continue;

            for (int k = 0; k < 4; k++) {
                int ni = i + dirs[k][0];
                int nj = j + dirs[k][1];

                if (ni >= 0 && ni < n && nj >= 0 && nj < m) { 
                    int newEffort = max(eff, abs(heights[i][j] - heights[ni][nj]));

                    if (newEffort < efforts[ni][nj]) {
                        efforts[ni][nj] = newEffort;
                        pq.push({newEffort, {ni, nj}});
                    }
                }
            }
        }
        return efforts[n-1][m-1];
    }
};
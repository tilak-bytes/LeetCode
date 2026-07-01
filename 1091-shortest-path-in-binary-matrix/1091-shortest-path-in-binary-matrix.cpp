class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;
        if (n == 1) return 1;

        int dirs[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;

        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 1});

        while(!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int dis = q.front().second;
            q.pop();

            for(int k = 0; k < 8; k++) {
                int ni = i + dirs[k][0];
                int nj = j + dirs[k][1];

                if(ni >= 0 && ni < n && nj >= 0 && nj < n && 
                        grid[ni][nj] == 0 && !visited[ni][nj]) {

                    if (ni == n-1 && nj == n-1) return dis + 1;     // reached!

                    visited[ni][nj] = true;
                    q.push({{ni, nj}, dis + 1});
                }

            }
        }
        return -1;
    }
};
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        int dirs[8][2] = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
                          {1, 0},  {1, -1}, {0, -1}, {-1, -1}};

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 0}});
        visited[0][0] = true;

        while (!q.empty()) {
            auto front = q.front();
            int steps = front.first;
            auto [row, col] = front.second;
            q.pop();

            if (row == n - 1 && col == n - 1)
                return steps + 1;

            for (auto [i, j] : dirs) {
                int nr = row + i;
                int nc = col + j;

                if (nr >= 0 && nc >= 0 && nr < n && nc < n &&
                    grid[nr][nc] == 0 && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    q.push({steps + 1, {nr, nc}});
                }
            }
        }
        return -1;
    }
};
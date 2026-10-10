class Solution {
  public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        priority_queue<tuple<int,int,int>,
                       vector<tuple<int,int,int>>,
                       greater<>> pq;   // {time, r, c}

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0});

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto [time, r, c] = pq.top();
            pq.pop();

            if (r == n - 1 && c == n - 1) return time;
            if (time > dist[r][c]) continue;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;

                int newTime = max(time, grid[nr][nc]);
                if (newTime < dist[nr][nc]) {
                    dist[nr][nc] = newTime;
                    pq.push({newTime, nr, nc});
                }
            }
        }
        return -1;
    }
};
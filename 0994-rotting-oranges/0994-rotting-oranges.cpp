class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++){

                if(grid[i][j] == 1) fresh++;

                else if(grid[i][j] == 2) q.push({i, j});
            }
        }
        // 4 directions - up down left right
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int minutes = 0;

        while(!q.empty() && fresh > 0){
            int size = q.size();

            for(int k = 0; k < size ; k++){
                auto [i, j] = q.front();
                q.pop();

                for(auto dir : dirs){
                    int ni = i + dir[0];
                    int nj = j + dir[1];

                    // if neighbor is fresh, make it rotten
                    if(ni >= 0 && ni < n && nj >= 0 && nj < m
                            && grid[ni][nj] == 1){
                        grid[ni][nj] = 2;
                        fresh--;
                        q.push({ni, nj});
                    }
                }
            }
            minutes++;
        }

        return (fresh == 0) ? minutes : -1;
    }
};
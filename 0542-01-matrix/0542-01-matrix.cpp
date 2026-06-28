class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++) {
                if(mat[i][j] == 0){ 
                    q.push({{i, j}, 0});
                    visited[i][j] = true;
                }
            }
        }
        vector<vector<int>> result(m, vector<int>(n, 0));

        //Directions: Up, Right, Down, Left
        int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        while(!q.empty()){
            int i  = q.front().first.first;
            int j = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            result[i][j] = steps;

            for(int k = 0 ; k < 4 ; k++){
                int ni = i + dirs[k][0];
                int nj = j + dirs[k][1];

                if(ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni][nj]){
                    visited[ni][nj] = true;
                    q.push({{ni, nj}, steps + 1});
                }
            }
        }
        return result;
    }
};
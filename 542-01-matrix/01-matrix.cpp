class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> result (n, vector<int>(m, 0));
        vector<vector<int>> visited(n, vector<int>(m, 0));

        queue<pair<pair<int, int>, int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    visited[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }

        vector<int> dirx = {-1, 1, 0, 0};
        vector<int> diry = {0, 0, -1, 1};

        while(!q.empty()) {
            auto it = q.front();
            int x = it.first.first;
            int y = it.first.second;
            int steps = it.second;
            q.pop(); 

            result[x][y] = steps;

            for(int k=0;k<4;k++) {
                int nx = x + dirx[k];
                int ny = y + diry[k];

                if(nx>=0 && nx<n && ny>=0 && ny<m && visited[nx][ny] == 0){
                    visited[nx][ny] = 1;
                    q.push({{nx, ny}, steps+1});
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> distanceMatrix(n, vector<int>(m, -1));
        queue<pair<pair<int, int>, int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    distanceMatrix[i][j] = 0;
                }
            }
        }

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        while(!q.empty()){
            auto item = q.front();
            q.pop();
            int x = item.first.first;
            int y = item.first.second;
            int dist = item.second;

            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx >= 0 && ny >= 0 && nx < n && ny < m && distanceMatrix[nx][ny] == -1) {
                    distanceMatrix[nx][ny] = dist + 1;
                    q.push({{nx, ny}, dist + 1});  
                }
            }
        }

        return distanceMatrix;
    }
};

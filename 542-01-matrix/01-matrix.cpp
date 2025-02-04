class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis (n, vector<int>(m, 0));
        vector<vector<int>> dist (n, vector<int>(m, 0));

        queue<pair<pair<int, int>, int>> q;

        vector<int> dirX = {-1, 1, 0, 0};
        vector<int> dirY = {0, 0, -1, 1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }else {
	                vis[i][j] = 0; 
	            }
            }
        }

        while(!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            dist[x][y] = steps;

            for(int i = 0;i<4;i++){
                int newX = x + dirX[i];
                int newY = y + dirY[i];

                if(newX >= 0 && newX < n && newY>=0 && newY < m && vis[newX][newY] == 0) {
                    q.push({{newX, newY}, steps+1});
                    vis[newX][newY] = 1;
                }
            }

        }
        return dist;
    }
};
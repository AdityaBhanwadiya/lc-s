class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<int, int>> q;
        
        vector<int> dirx = {-1, 1, 0, 0};
        vector<int> diry = {0, 0, -1, 1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i == 0 || i == n-1 || j == 0 || j == m-1) {
                    if(grid[i][j] == 1){
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int k = 0;k<4;k++){
                int nx = x + dirx[k];
                int ny = y + diry[k];

                if(nx >= 0 && nx < n && ny>=0 && ny < m && grid[nx][ny] == 1 && vis[nx][ny] == 0) {
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }

        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && vis[i][j] == 0)
                    count++;
            }
        }
        return count;
    }
};
class Solution {
private:
    void dfs(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& vis, vector<int>& dx, vector<int>& dy) {
        vis[i][j] = 1;

        for(int k=0;k<4;k++){
            int nx = i + dx[k];
            int ny = j + dy[k];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1 && vis[nx][ny] == 0){
                vis[nx][ny]=1;
                dfs(nx, ny, n, m, grid, vis, dx, dy);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis (n, vector<int> (m, 0));

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    if(grid[i][j] == 1 && vis[i][j] == 0) {
                        dfs(i, j, n, m, grid, vis, dx, dy);
                    }
                }
            }
        }

        int count = 0;

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++) {
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    count++;
                }
            }
        }
        return count;
    }
};
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||j==0||i==n-1||j==m-1){
                    if(grid[i][j] == 1){
                        grid[i][j] = 0;
                        q.push({i, j});
                    }
                }
            }
        }

        vector<int> dirx = {-1, 1, 0, 0};
        vector<int> diry = {0, 0, -1, 1};


        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for(int k=0;k<4;k++) {
                int nx = x + dirx[k];
                int ny = y + diry[k];

                if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny] == 1){
                    grid[nx][ny] = 0;
                    q.push({nx, ny});
                }
            }
        }

        int ones = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1)
                    ones++;
            }
        }

        return ones;
    }
};


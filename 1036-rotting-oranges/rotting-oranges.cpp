class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // classic bfs problem
        // keep coutn of fresh oranges and store rotten in queue

        queue<pair<int, int>> q;
        int fresh = 0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 1) fresh++;
                else if(grid[i][j] == 2)    {
                    q.push({i, j});
                }
            }
        }

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        int minutes = 0;

        while(!q.empty()) {
            int size = q.size();

            for(int i=0;i<size;i++) {
                auto [x, y] = q.front();
                q.pop();

                for(int k =0;k<4;k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if(nx<n && nx >= 0 && ny<m && ny>=0 && grid[nx][ny] == 1){
                        fresh--;
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                    }
                }
            }  
            minutes++;
        }
        if(minutes> 0)  minutes--;
        if(fresh == 0)  return minutes;
        return -1;
    }
};
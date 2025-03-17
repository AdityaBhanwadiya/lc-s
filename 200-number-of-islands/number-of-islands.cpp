class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        queue<pair<int, int>> q;

        vector<vector<int>> visited(n, vector<int>(m, 0));

        int islands = 0;


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && visited[i][j] == 0){
                    islands++;
                    q.push({i, j});
                    visited[i][j] = 1;

                    while(!q.empty()){
                        auto item = q.front();
                        q.pop();
                        int x = item.first;
                        int y = item.second;

                        for(int i=0;i<4;i++){
                            int nx = x + dx[i];
                            int ny = y + dy[i];

                            if(nx >= 0 && ny >= 0 && nx < n && ny < m && visited[nx][ny] == 0 && grid[nx][ny] == '1'){
                                visited[nx][ny] = 1;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
        
    return islands;
    }
};
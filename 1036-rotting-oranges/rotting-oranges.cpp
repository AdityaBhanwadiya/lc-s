class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        vector<int> dirx = {-1, 1, 0, 0};
        vector<int> diry = {0, 0, -1, 1};

        int mins = 0;

        while(!q.empty()) {
            int size = q.size();

            for(int i=0;i<size;i++) {
                auto item = q.front();
                q.pop();
                
                for(int k=0;k<4;k++) {
                    int nx = dirx[k] + item.first;
                    int ny = diry[k] + item.second;

                    if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny] == 1) {
                        fresh--;
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                    }
                }
            }
            mins++;
        }
        // last round might be off with no fresh oranges
        if (mins > 0) mins--;
        if(fresh == 0)  return mins;
        return -1;
    }
};
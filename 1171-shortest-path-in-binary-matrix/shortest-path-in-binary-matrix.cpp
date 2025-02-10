class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)  return -1;

        // initial config
        vector<vector<int>> dist (n, vector<int> (n, 1e9));

        dist[0][0] = 1;

        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0,0}});

        vector<int> distx = {-1, 1, 0, 0, 1, -1, 1, -1};
        vector<int> disty = {0, 0, -1, 1, 1, -1, -1, 1};

        int length = 0;

        while(!q.empty()) {
            auto cell = q.front();
            int distance = cell.first;
            int row = cell.second.first;
            int col = cell.second.second;
            q.pop();

            if(row == n-1 && col == n-1)    return distance;

            for(int i = 0;i<8;i++){
                int nx = row + distx[i];
                int ny = col + disty[i];

                if(nx>=0 && nx<dist.size() && ny>=0 && ny < dist.size() && grid[nx][ny] == 0) {
                    if(distance + 1 < dist[nx][ny]){
                        dist[nx][ny] = distance + 1;
                        q.push({distance + 1, {nx, ny}});
                    }
                }
            }
        }
        return -1;
    }
};
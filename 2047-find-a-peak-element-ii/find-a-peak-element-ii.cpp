class Solution {
private:
    bool isPeak(int x, int y, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                if (mat[nx][ny] > mat[x][y]) return false;
            }
        }
        return true;
    }
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};


    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    
                    while (!q.empty()) {
                        auto [x, y] = q.front(); q.pop();
                        
                        if (isPeak(x, y, mat)) {
                            return {x, y}; 
                        }

                        for (int d = 0; d < 4; d++) {
                            int nx = x + dx[d];
                            int ny = y + dy[d];
                            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                                visited[nx][ny] = true;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
        return {-1, -1};
    }
};
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1; 

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        queue<pair<int, pair<int, int>>> q;

        vector<int> dx = {-1, 1, 0, 0, 1, 1, -1, -1};
        vector<int> dy = {0, 0, -1, 1, 1, -1, 1, -1};

        q.push({1, {0, 0}});
        dist[0][0] = 1;

        while (!q.empty()) {
            auto [d, cell] = q.front();
            auto [r, c] = cell;
            q.pop();

            if (r == n - 1 && c == n - 1)
                return d;

            for (int k = 0; k < 8; k++) {
                int newR = r + dx[k];
                int newC = c + dy[k];

                if (newR >= 0 && newC >= 0 && newR < n && newC < n && grid[newR][newC] == 0) {
                    if (dist[newR][newC] > d + 1) {
                        dist[newR][newC] = d + 1;
                        q.push({d + 1, {newR, newC}});
                    }
                }
            }
        }

        return -1;
    }
};

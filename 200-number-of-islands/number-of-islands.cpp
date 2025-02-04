class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // Declare visited vector of same size as grid with all 0's
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));

        // Declare queue for BFS
        queue<pair<int, int>> q;

        // Island counter
        int count = 0;

        // Directions for BFS (Up, Down, Left, Right)
        vector<int> dirsX = {-1, 1, 0, 0};
        vector<int> dirsY = {0, 0, -1, 1};

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                // If land is found and not visited, start BFS
                if (grid[i][j] == '1' && visited[i][j] == 0) {
                    count++;
                    visited[i][j] = 1;  // Mark as visited
                    q.push({i, j});

                    // BFS traversal
                    while (!q.empty()) {
                        auto it = q.front();
                        q.pop();

                        for (int k = 0; k < 4; k++) {
                            int newX = it.first + dirsX[k];
                            int newY = it.second + dirsY[k];

                            // Check if within bounds and unvisited land
                            if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size()
                                && grid[newX][newY] == '1' && visited[newX][newY] == 0) {
                                visited[newX][newY] = 1;
                                q.push({newX, newY});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};

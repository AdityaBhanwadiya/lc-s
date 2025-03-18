class Solution {
private:
    void dfs(int i, int j, int n, int m, vector<vector<char>>& board, vector<vector<int>>& vis, vector<int>& dx, vector<int>& dy) {
        vis[i][j] = 1;

        for(int k=0;k<4;k++){
            int nx = i + dx[k];
            int ny = j + dy[k];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == 'O' && vis[nx][ny] == 0){
                vis[nx][ny]=1;
                dfs(nx, ny, n, m, board, vis, dx, dy);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis (n, vector<int> (m, 0));

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    if(board[i][j] == 'O' && vis[i][j] == 0) {
                        dfs(i, j, n, m, board, vis, dx, dy);
                    }
                }
            }
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++) {
                if(board[i][j] == 'O' && vis[i][j] == 0){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
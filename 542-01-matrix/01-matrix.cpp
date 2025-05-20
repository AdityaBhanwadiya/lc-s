class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();


        // you gotta use bfs and store the dist as well in q
        queue<pair<int, pair<int, int>>> q;

        // create seperate result
        vector<vector<int>> result (n, vector<int> (m, 0));

        // visited as well
        vector<vector<int>> visited (n, vector<int> (m, 0));

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mat[i][j] == 0){
                    visited[i][j] = 1;
                    q.push({0, {i, j}});
                }
            }
        }

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        while(!q.empty()) {
            auto item = q.front();
            int dist = item.first;
            int x = item.second.first;
            int y = item.second.second;

            q.pop();

            for(int k=0;k<4;k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx<n && nx>=0 && ny<m && ny>=0 && !visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    result[nx][ny] = dist+1;
                    q.push({result[nx][ny], {nx, ny}});
                }
            }
        }
        return result;
    }
};
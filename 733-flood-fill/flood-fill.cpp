class Solution {
private:
    void dfs(vector<vector<int>>& copyImage, int sr, int sc, int color, int startColor, vector<int> dx, vector<int> dy) {
        copyImage[sr][sc] = color;
    
        int n = copyImage.size();
        int m = copyImage[0].size();

        for(int i=0;i<4;i++) {
            int nx = sr + dx[i];
            int ny = sc + dy[i];

            if(nx >= 0 && ny>= 0 && nx<n && ny < m && copyImage[nx][ny] == startColor && copyImage[nx][ny] != color){
                dfs(copyImage, nx, ny, color, startColor, dx, dy);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int startColor = image[sr][sc];
        vector<vector<int>> copyImage = image;

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        dfs(copyImage, sr, sc, color, startColor, dx, dy);
        return copyImage;
    }
};
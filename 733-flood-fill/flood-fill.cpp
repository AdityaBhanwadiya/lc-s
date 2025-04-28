class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        queue<pair<int, int>> q;
        q.push({sr, sc});
        int iColor = image[sr][sc];

        if(iColor == color) return image;
        
        image[sr][sc] = color;


        vector<int> dirX = {-1, 1, 0, 0};
        vector<int> dirY = {0, 0, -1, 1};

        while(!q.empty()) {
            auto item = q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int nx = item.first + dirX[k];
                int ny = item.second + dirY[k];

                if(nx>=0 && nx<n && ny>=0 && ny<m && image[nx][ny] == iColor){
                    image[nx][ny] = color;
                    q.push({nx, ny});
                }
            }

        }
        return image;
    }
};
class Solution {
public:
    bool dfs(int start, int wantedColor, vector<int>& color, vector<vector<int>>& graph) {
        color[start] = wantedColor;

        for(int neighbor : graph[start]) {
            if(color[neighbor] == -1){
                if(dfs(neighbor, !wantedColor, color, graph) == false)   return false;
            }else if(color[neighbor] == color[start])
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color (n, -1);

        for(int i=0;i<n;i++) {
            if(color[i] == -1){
                if(dfs(i, 0, color, graph) == false){
                    return false;
                }
            }
        }
        return true;
    }
};
class Solution {
private:
    bool bfs(int start, vector<vector<int>>& graph, vector<int>& color) {
       queue<int> q;
       q.push(start);

        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            for(auto neighbor: graph[node]) {
                if(color[neighbor] == -1){
                    color[neighbor] = 1 - color[node];
                    q.push(neighbor);
                }else if(color[neighbor] == color[node]) {
                    return false;
                }
            }
        }
        return true;   
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = graph[0].size();

        vector<int> color (n, -1); // uncolored

        for(int i=0;i<n;i++){
            if (color[i] == -1){
                // colored the parent now do neighbors
                color[i] = 0;
                if(!bfs(i, graph, color))    return false;
            }
        }
        return true;
    }
};
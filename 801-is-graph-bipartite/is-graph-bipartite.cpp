class Solution {
private: 
    bool check (int start, vector<int> &color, vector<vector<int>>& graph) {
        queue<int> q;

        q.push(start);
        color[start] = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int neighbor : graph[node]) {
                if(color[neighbor] == -1) { 
                    // Assign opposite color
                    color[neighbor] = 1 - color[node];  
                        q.push(neighbor);
                } 
                else if(color[neighbor] == color[node]) {  
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

        // store coloring of nodes
        vector<int> color(n, -1);

        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if(check(i, color, graph) == false)
                    return false;
            }
        }
        return true;
    }
};
class Solution {
public:

    bool dfs(int node, int n, vector<int>& vis, vector<int>& path, vector<int>& status, vector<vector<int>>& graph) {
        vis[node] = 1;
        path[node] = 1;
        
        for(int neighbour : graph[node]) {
            if(vis[neighbour] == 0) { 
                if(dfs(neighbour, n, vis, path, status, graph)) {
                    status[neighbour] = 0;
                    return true;
                }
            } else if(path[neighbour] == 1) {  
                // Cycle detected
                status[neighbour] = 0;
                return true;
            }
        }
        
        // Backtrack
        status[node] = 1;
        path[node] = 0;  
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> safe;
        vector<int> nodeStatus(n, -1);
        int flag = 0;
        
        vector<int> vis(n, 0);
        vector<int> path(n, 0);
        
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i, n, vis, path, nodeStatus, graph);
            }
        }

        for (int i = 0; i < n; i++) {
            if (nodeStatus[i] == 1) {
                safe.push_back(i);
            }
        }
        return safe;
    }
};
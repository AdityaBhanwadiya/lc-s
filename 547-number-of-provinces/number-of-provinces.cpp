class Solution {
public:
    void dfs(int node, vector<vector<int>>& adjList, vector<int>& vis) {
        vis[node] = 1;
        for (auto neighbor : adjList[node]) {
            if (!vis[neighbor]) {
                dfs(neighbor, adjList, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjList(n); // Initialize adjacency list

        // Create adjacency list
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] == 1 && i != j) { // Avoid self-loops
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        vector<int> vis(n, 0);
        int count = 0;

        // Count connected components
        for(int i = 0; i < n; i++) {
            if (!vis[i]) {
                count++;
                dfs(i, adjList, vis);
            }
        }
        return count;
    }
};

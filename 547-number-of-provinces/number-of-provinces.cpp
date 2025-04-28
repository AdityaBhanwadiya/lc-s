class Solution {
    int comp = 0;
private:
    void dfs(int start, vector<vector<int>>& adjacencyList, vector<int>& visited) {
        visited[start] = 1;

        for(auto it : adjacencyList[start]) {
            if(!visited[it]) {
                dfs(it, adjacencyList, visited);
            }
        }
    }

    vector<vector<int>> createAdjList (vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();

        vector<vector<int>> adjacencyList (n);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adjacencyList[i].push_back(j);
                    adjacencyList[j].push_back(i);
                }
            }
        }
        return adjacencyList;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited (n, 0);

        vector<vector<int>> adjacencyList = createAdjList(isConnected);

        for(int i=0;i<n;i++) {
            if(!visited[i]){
                comp++;
                dfs(i, adjacencyList, visited);
            }
        }

        return comp;

    }
};
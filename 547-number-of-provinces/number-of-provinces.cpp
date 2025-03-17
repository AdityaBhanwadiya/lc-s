class Solution {
private:
    void createAdjList (vector<vector<int>>& adjM, vector<vector<int>>& adjL) {
        int n = adjM.size();
        int m = adjM[0].size();

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++){
                if(adjM[i][j] == 1 && i!=j){
                    adjL[i].push_back(j);
                    adjL[j].push_back(i);
                }
            }
        }
    }

    void dfs(int node, vector<vector<int>>& adjList, vector<int>& visited) {
        visited[node] = 1;

        for(auto i : adjList[node]){
            if(!visited[i]){
                dfs(i, adjList, visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<vector<int>> adjList(n);

        createAdjList(isConnected, adjList);

        vector<int> visited(n, 0);

        int count=0;

        for(int i=0;i<n;i++) {
            if(!visited[i]){
                count++;
                dfs (i, adjList, visited);
            }
        }
        return count;
    }
};
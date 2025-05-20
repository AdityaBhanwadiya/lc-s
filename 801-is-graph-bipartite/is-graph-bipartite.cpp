class Solution {
private:

    bool dfs(int start, int wanted, vector<vector<int>>& adjList, vector<int>& color) {
        color[start] = wanted;

        for(auto it : adjList[start]) {
            if(color[it] == -1){
                if(!dfs(it, 1-wanted, adjList, color)){
                    return false;
                }
            }else if(color[it] == color[start]) {
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // youll need vector to store the colors
        // multiple components possible


        int n = graph.size();

        vector<int> color (n, -1);

        for(int i=0;i<n;i++) {
            if(color[i] == -1) {
                if(!dfs(i, 0, graph, color)) return false;
            }
        }
        return true;
    }
};
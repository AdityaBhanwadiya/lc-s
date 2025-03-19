class Solution {
private:
    vector<int> findOrder(int numCourses, vector<vector<int>>& adjList, vector<int>& indegree) {
        vector<int> topo;
        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }


        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it : adjList[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        sort(topo.begin(), topo.end());
        return topo;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<vector<int>> reversedgraph(n);
        vector<int> indegree(n, 0);

        for(int i=0;i<n;i++){
            for(auto it: graph[i]) {
                reversedgraph[it].push_back(i);
                indegree[i]++;
            }
        }

        return findOrder (n, reversedgraph, indegree);
    }
};
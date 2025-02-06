class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // Using topological sort
        vector<int> safeNodes;

        int numCourses = graph.size();
        // indegree 
        vector<int> indegree (numCourses, 0);

        vector<vector<int>> revGraph(numCourses);
        for(int i=0;i<numCourses;i++) {
            for(auto it : graph[i]){
                revGraph[it].push_back(i);
                indegree[i]++;
            }
        }

        // queue
        queue<int> q;

        for (int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }


        while(!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for(auto i : revGraph[node]) {
                indegree[i]--;

                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
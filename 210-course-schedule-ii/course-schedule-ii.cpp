class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int> topo;
        queue<int> q;

        for (auto& pre : prerequisites) {
            int course = pre[0], prereq = pre[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }


        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return topo.size() == numCourses ? topo : vector<int>();
    }
};
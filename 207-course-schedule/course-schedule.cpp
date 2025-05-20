class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        // [1, 0] means to take 1, you gtta take 0 first
        // Take v before u
        // SOmething before soemthing -> Topo Sort
        // Kahns algo -> indegree vector, queue, adjList

        vector<vector<int>> adjList(numCourses);
        for (auto &p : pre) {
            adjList[p[1]].push_back(p[0]);
        }


        vector<int> indegree (numCourses, 0);
        for(int i=0;i<numCourses;i++){
            for(auto it : adjList[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }


        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            for(auto it : adjList[node]) {
                indegree[it]--;

                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        for(auto it:indegree){
            if(it != 0) return false;
        }
        return true;
    }
};
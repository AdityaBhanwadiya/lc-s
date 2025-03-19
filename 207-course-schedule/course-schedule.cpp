class Solution {
private:
    bool checkCycles (int start, vector<int>& vis, vector<int>& path, vector<vector<int>>& prereq)     {   
        vis[start] = 1;
        path[start] = 1;

        for (int neighbor : prereq[start]) {
            if (!vis[neighbor]) {  
                if (checkCycles(neighbor, vis, path, prereq)) 
                    return true; 
            } 
            else if (path[neighbor]) {
                return true; 
            }
        }
        path[start] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, 0);
        vector<int> path (numCourses, 0);

        vector<vector<int>> adjList(numCourses);
        for (auto &p : prerequisites) {
            adjList[p[1]].push_back(p[0]);
        }
        
        for(int i=0;i<numCourses;i++){
            // If cycle found
            if(!visited[i] && checkCycles(i, visited, path, adjList)) 
                return false;
        }
        return true;
    }
};
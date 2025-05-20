class Solution {
private:
    bool dfs(int i, stack<int>& st, vector<int>& vis, vector<int>& rec, vector<vector<int>>& adjList) {
        vis[i] = 1;
        rec[i] = 1;

        for (auto it : adjList[i]) {
            if (!vis[it]) {
                if (!dfs(it, st, vis, rec, adjList)) return false;
            } else if (rec[it]) {
                return false; 
            }
        }

        rec[i] = 0;
        st.push(i);
        return true;
    }

public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adjList(n);
        for (auto it : pre) {
            adjList[it[1]].push_back(it[0]);
        }

        stack<int> st;
        vector<int> vis(n, 0), rec(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (!dfs(i, st, vis, rec, adjList)) return {}; 
            }
        }

        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};

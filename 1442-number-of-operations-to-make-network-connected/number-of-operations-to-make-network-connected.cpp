class Disjointset {
public:
    vector<int> rank, parent;
    Disjointset(int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);

        for(int i=0;i<=n;i++)
            parent[i]=i;
    }
    int findParent(int node) {
        if(parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank (int u, int v) {
        int ulpu = findParent(u);
        int ulpv = findParent(v);

        if(ulpu == ulpv)    return;
        if(rank[ulpu] == rank[ulpv]){
            parent[ulpu] = ulpv;
            rank[ulpv]++;
        }else if(rank[ulpu] < rank[ulpv]){
            parent[ulpu] = ulpv;
        }else{
            parent[ulpv] = ulpu;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1)    return -1;
        Disjointset ds(n);

        for(auto it : connections) {
            if(ds.findParent(it[0]) != ds.findParent(it[1])){
                ds.unionByRank(it[0], it[1]);
            }
        }

        int components = 0;
        for(int i=0;i<n;i++){
            if(ds.parent[i] == i)
                components++;
        }
        return components-1;
    }
};

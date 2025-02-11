class DisjointSets {

public:
    vector<int> rank, size, parent;
    DisjointSets(int n) {
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1);

        for(int i=1;i<=n;i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void findUnionByRank (int u, int v) {
        int ul_pu = findParent(u);
        int ul_pv = findParent(v);

        if(ul_pu == ul_pv)  return;

        if(rank[ul_pu] < rank[ul_pv]) {
            parent[ul_pu] = ul_pv;
        }else if(rank[ul_pv] < rank[ul_pu]){
            parent[ul_pv] = ul_pu;
        }else{
            parent[ul_pv] = ul_pu;
            rank[ul_pu]++;
        }
    }

    void findUnionBySize(int u, int v) {
        int ul_pu = findParent(u);
        int ul_pv = findParent(v);

        if(ul_pu == ul_pv)  return;
        if(size[ul_pu] < size[ul_pv]) {
            parent[ul_pu] = ul_pv;
            size[ul_pv] += size[ul_pu];
        }else{
            parent[ul_pv] = ul_pu;
            size[ul_pu] += size[ul_pv];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSets ds(n);
        int cntExtras = 0;
        for (auto it : connections) {
            int u = it[0];
            int v = it[1];
            if (ds.findParent(u) == ds.findParent(v)) {
                cntExtras++;
            }
            else {
                ds.findUnionBySize(u, v);
            }
        }
        int cntC = 0;
        for (int i = 0; i < n; i++) {
            if (ds.parent[i] == i) cntC++;
        }
        int ans = cntC - 1;
        if (cntExtras >= ans) return ans;
        return -1;
    }
};
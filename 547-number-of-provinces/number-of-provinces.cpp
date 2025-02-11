class DisjointSets {
    vector<int> rank, size, parent;

public:
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSets ds(n);

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if (isConnected[i][j] == 1)
                    ds.findUnionBySize(i, j);
            }
        }

        int count = 0;
        for(int i=0;i<n;i++){
            if(ds.findParent(i) == i)   count++;
        }
    return count;
    }
};
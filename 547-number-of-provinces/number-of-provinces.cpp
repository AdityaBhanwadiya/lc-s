class DisjointSet {
  vector<int> rank, parent, size;
  
 public:
    DisjointSet(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        
        size.resize(n+1, 1);
    }
    
    int findParent (int node) {
        if(node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }
    
    void unionByRank (int u, int v){
        int ulu = findParent(u);
        int ulv = findParent(v);
        
        if(ulu == ulv)  return;
        if(rank[ulu] > rank[ulv]){
            parent[ulv] = ulu;
        }
        else if(rank[ulv] > rank[ulu]){
            parent[ulu] = ulv;
        }else{
            parent[ulu] = ulv;
            rank[ulv]++;
        }
    }
    
    
    void unionBySize (int u, int v){
        int ulu = findParent(u);
        int ulv = findParent(v);
        
        if(ulu == ulv)  return;
        if(size[ulu] > rank[ulv]){
            parent[ulv] = ulu;
            size[ulu] += size[ulv];
        }
        else if(rank[ulv] > rank[ulu]){
            parent[ulu] = ulv;
            size[ulv] += size[ulu];
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n);

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if (isConnected[i][j] == 1)
                    ds.unionBySize(i, j);
            }
        }

        int count = 0;
        for(int i=0;i<n;i++){
            if(ds.findParent(i) == i)   count++;
        }
        return count;
    }
};
class DisjointSet{
public : 
    vector<int> parent, size;

    DisjointSet(int n){
        parent.resize(n);
        size.resize(n,1);
        
        for(int i = 0 ; i< n ; i++) parent[i]=i;
    }

    int findPar(int x){
        if(parent[x]==x) return x;
        return parent[x]=findPar(parent[x]);
    }

    void unionBySize(int u , int v){
        int pu = findPar(u);
        int pv = findPar(v);

        if(pv == pu) return ;

        if(size[pu]<size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
  
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() < n-1) return -1;

        DisjointSet ds(n);

        int components = 0;

        for(auto &it : connections){
           ds.unionBySize(it[0],it[1]);

        }

        for(int i = 0 ; i< n ;i++){
            if(ds.findPar(i)==i)components++;
        }
        return components - 1;
    }
};
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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,-1,1};

        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j< n ;j++){
                if(grid[i][j]==0)continue;
                for(int k = 0;k<4;k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx>=0 && ny>=0 && nx<n && ny<n){
                        if(grid[nx][ny]==1){
                            int nodeNo = i*n + j;
                            int adjNo = nx*n +ny;
                            ds.unionBySize(nodeNo,adjNo);
                        }
                    }
                }
            }
        }
        int ans = 0;
        
        for(int i = 0 ; i< n ; i++){
            for(int j =0 ; j<n ;j++){
                if(grid[i][j]==1) continue;
                int sum = 1;
                unordered_set<int> st;
                for(int k = 0 ; k< 4 ; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx>=0 && ny>=0 && nx<n && ny<n){
                        if(grid[nx][ny]==1){
                            st.insert(ds.findPar(nx*n + ny));
                        }
                    }
                }
                for(int x : st){
                    sum += ds.size[x];
             
                }
                ans = max(ans,sum);
            }
        }
        for(int i = 0 ; i< n*n; i++){
            ans = max(ans,ds.size[ds.findPar(i)]);
        }
        return ans;
    }
};
class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return;

        if (rank[px] < rank[py])
            parent[px] = py;
        else if (rank[px] > rank[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxR = 0 , maxC = 0;
        for(auto & it : stones){
            maxR = max(it[0],maxR);
            maxC = max(it[1],maxC);
        }
        int n = stones.size();
        DSU ds(maxR+maxC+2);
        unordered_set<int> st;

        for(auto it : stones){
            int nodeR = it[0];
            int nodeC = it[1]+1+maxR;
            ds.unite(nodeR,nodeC);
            st.insert(nodeR);
            st.insert(nodeC);
        }

        int cnt =0;
        for(auto it : st){
            if(ds.find(it)==it) cnt++;
        }
        return n - cnt;
    }
};
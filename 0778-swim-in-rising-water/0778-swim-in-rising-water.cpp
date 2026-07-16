class Solution {
public:
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

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int total = n * n;

        // position[value] = {row, col}
        vector<pair<int,int>> pos(total);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pos[grid[i][j]] = {i, j};
            }
        }

        DSU dsu(total);
        vector<vector<bool>> open(n, vector<bool>(n, false));

        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        for (int t = 0; t < total; t++) {

            auto [r, c] = pos[t];
            open[r][c] = true;

            int id = r * n + c;

            for (auto [dr, dc] : dirs) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                    continue;

                if (!open[nr][nc])
                    continue;

                int nid = nr * n + nc;
                dsu.unite(id, nid);
            }

            if (dsu.find(0) == dsu.find(total - 1))
                return t;
        }

        return -1;
    }
};
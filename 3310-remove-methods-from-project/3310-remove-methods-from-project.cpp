class Solution {
public:
    void dfs(int u, vector<int> &vis, vector<vector<int>> &edges) {
        vis[u] = 1;
        for (int v : edges[u]) {
            if (!vis[v])
                dfs(v, vis, edges);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> edges(n);

        for (auto &e : invocations)
            edges[e[0]].push_back(e[1]);

        vector<int> vis(n, 0);
        dfs(k, vis, edges);

        // If an outside method calls a suspicious one,
        // no methods can be removed.
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            for (int adj : edges[i]) {
                if (vis[adj]) {
                    vector<int> ans;
                    for (int j = 0; j < n; j++)
                        ans.push_back(j);
                    return ans;
                }
            }
        }

        // Return remaining (non-suspicious) methods.
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                ans.push_back(i);
        }

        return ans;
    }
};
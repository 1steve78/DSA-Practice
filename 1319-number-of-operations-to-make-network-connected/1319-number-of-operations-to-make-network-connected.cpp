class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& graph) {
        vis[node] = 1;

        for (int adj : graph[node]) {
            if (!vis[adj])
                dfs(adj, vis, graph);
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;

        vector<vector<int>> graph(n);

        for (auto &it : connections) {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, vis, graph);
                components++;
            }
        }

        return components - 1;
    }
};
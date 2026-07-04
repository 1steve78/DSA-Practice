class Solution {
public:
    int bfs(int start, vector<vector<pair<int,int>>> &graph,
            vector<int> &vis) {

        queue<int> q;
        q.push(start);
        vis[start] = 1;

        int mn = INT_MAX;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto &it : graph[node]) {
                int adj = it.first;
                int wt = it.second;

                mn = min(mn, wt);

                if (!vis[adj]) {
                    vis[adj] = 1;
                    q.push(adj);
                }
            }
        }

        return mn;
    }

    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> graph(n + 1);

        for (auto &road : roads) {
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }

        vector<int> vis(n + 1, 0);

        return bfs(1, graph, vis);
    }
};
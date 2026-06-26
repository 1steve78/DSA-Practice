class Solution {
public:
    bool dfs(int node,
        vector<int>& vis,
        vector<int>& pathVis,
        vector<int>& topo,
        vector<vector<int>>& graph)
    {
        vis[node] = 1;
        pathVis[node] = 1;

        for(int adj : graph[node]) {
            if(!vis[adj]) {
                if(dfs(adj, vis, pathVis, topo, graph))
                    return true;
            }
            else if(pathVis[adj]) {
                return true;          // cycle found
            }
        }

        pathVis[node] = 0;
        topo.push_back(node);         // postorder push
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);

        for (auto& p : prerequisites)
            graph[p[1]].push_back(p[0]);


        vector<int> ans;
        vector<int> vis(numCourses, 0), pathVis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, pathVis,ans, graph))
                    return {};
            }
        }



        reverse(ans.begin(), ans.end());
        return ans;
  
    }
};
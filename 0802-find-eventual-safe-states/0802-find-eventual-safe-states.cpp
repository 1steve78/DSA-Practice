class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> RevGraph(n);
        vector<int> inDegree(n,0);

        for(int i =0 ; i<n ;i++){
            for(int x : graph[i]){
                RevGraph[x].push_back(i);
                inDegree[i]++;
            }
        }

        queue<int> q;

        for(int i = 0 ; i<n ; i++){
            if(inDegree[i]==0) q.push(i);
        }
        vector<int> topo;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(int adjNode : RevGraph[node]){
                inDegree[adjNode]--;
                if(inDegree[adjNode]==0){
                    q.push(adjNode);
                }
            }

        }
        sort(topo.begin(),topo.end());
        return topo;

    }
};
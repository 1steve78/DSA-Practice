class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> colors(n,-1);
        for(int i = 0 ;i<n ;i++){
            if(colors[i]!=-1)continue;
            queue<int> q;
            colors[i]=0;
            q.push(i);

            while(!q.empty()){
                int u = q.front();
                
                q.pop();

                for(auto & v : graph[u]){
                    if(colors[v]==-1){
                        colors[v]=1-colors[u];
                        q.push(v);
                    }else if(colors[v]==colors[u]){
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};
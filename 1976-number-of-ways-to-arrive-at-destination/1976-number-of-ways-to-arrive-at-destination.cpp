class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int,int>>> graph(n);
        for(int i = 0 ; i< roads.size();i++){
            graph[roads[i][0]].push_back({roads[i][2],roads[i][1]});
            graph[roads[i][1]].push_back({roads[i][2],roads[i][0]});
        } 

        vector<long long > dist(n,LLONG_MAX) , ways(n,0);
        priority_queue<pair<long long ,long long >,vector<pair<long long ,long long >>,greater<pair<long long ,long long >>> pq;

        ways[0]=1;
        dist[0]=0;
        pq.push({0,0});

        while(!pq.empty()){

            auto [W, node] = pq.top();
            pq.pop();
            
            if (W > dist[node]) continue;
           
            for(auto & adj: graph[node]){
                int adjNode  = adj.second;
                int adjW = adj.first;

                if(W + adjW < dist[adjNode]){
                    dist[adjNode] = W + adjW;
                    pq.push({dist[adjNode],adjNode});
                    ways[adjNode] = ways[node];
                } else if( W + adjW == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }
        
        return ways[n-1] % MOD;
    }
};
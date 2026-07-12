class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adjL(n);
        for (auto flight: flights) {
            int u = flight[0], v = flight[1], w = flight[2];
            adjL[u].push_back({v, w});
           
        }
        
        queue<pair<int,pair<int,int>>> pq;

        pq.push({0,{src,0}});
        vector<int> dist(n,INT_MAX);
        int ans = INT_MAX;
        dist[src]=0;
        while(!pq.empty()){
            int stop =pq.front().first;
            int node = pq.front().second.first;
            int cost = pq.front().second.second;

            pq.pop();
            if(stop>k)continue;
            for(auto & adj : adjL[node]){
                int adjNode = adj.first;
                int adjCost = adj.second;
                if(cost+adjCost <dist[adjNode] && stop<=k){
                    dist[adjNode] = cost+adjCost;
                    pq.push({stop+1,{adjNode,dist[adjNode]}});
                    
                }
            }
        }
        
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};
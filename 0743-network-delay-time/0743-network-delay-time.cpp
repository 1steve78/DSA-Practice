class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);

        for(auto & a: times){
            graph[a[0]].push_back({a[2],a[1]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        vector<int> dist(n+1,INT_MAX);

        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int w = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();

            if (w > dist[node])
                continue;
            for(auto & adj : graph[node]){
                int adjNode = adj.second;
                int adjW = adj.first;
                if(w+adjW < dist[adjNode]){
                    dist[adjNode] =w + adjW;
                    pq.push({dist[adjNode],adjNode});

                }
            }
        }
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
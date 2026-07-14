class Solution {
public:
    vector<int> dijkstra(int src, vector<vector<pair<int,int>>>& graph){
        int n = graph.size();

        vector<int> dist(n, INT_MAX);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        dist[src] = 0;

        pq.push({0, src});

        while(!pq.empty())
        {
            auto [d, node] = pq.top();
            pq.pop();

            if(d > dist[node])
                continue;

            for(auto &[next, wt] : graph[node])
            {
                if(dist[node] + wt < dist[next])
                {
                    dist[next] = dist[node] + wt;
                    pq.push({dist[next], next});
                }
            }
        }

        return dist;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<pair<int,int>>> graph(n);

        for(auto & a : edges){
            graph[a[0]].push_back({a[1],a[2]});
            graph[a[1]].push_back({a[0],a[2]});
        }

        int answer = -1;
        int minReachable = INT_MAX;

        for(int city = 0; city < n; city++)
        {
            vector<int> dist = dijkstra(city, graph);

            int cnt = 0;

            for(int i = 0; i < n; i++)
            {
                if(i != city && dist[i] <= distanceThreshold)
                    cnt++;
            }

            if(cnt <= minReachable)
            {
                minReachable = cnt;
                answer = city;
            }
        }
        return answer;
    }
};
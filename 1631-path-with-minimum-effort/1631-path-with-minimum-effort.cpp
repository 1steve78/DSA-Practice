class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        int n = heights.size() , m = heights[0].size();
        if(n==1 && m==1) return 0;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,-1,1};
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        
        dist[0][0]=0;
        pq.push({0,{0,0}});
        
        int ans = INT_MAX;
        while(!pq.empty()){
            int currEffort = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;

            pq.pop();

            for(int i = 0 ; i<4 ;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx>=0 && ny>=0 && nx<n && ny<m){
                    int effort = abs(heights[x][y]-heights[nx][ny]);
                    int maxEffort = max(currEffort,effort);

                    if(maxEffort<dist[nx][ny]){
                        dist[nx][ny]=maxEffort;
                        pq.push({dist[nx][ny],{nx,ny}});

                        if(nx==n-1 && ny==m-1){
                            ans = min(dist[nx][ny],ans);
                        }
                    }
                }
            }
        }
        return ans;
    }
};
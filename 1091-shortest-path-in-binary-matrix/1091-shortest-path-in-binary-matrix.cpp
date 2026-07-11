class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        
        int n = grid.size() , m=grid[0].size();

        if(grid[0][0] || grid[n-1][m-1]) return -1;
        if(n == 1) return 1;

        int dx[8] ={1,-1,0,0,1,-1,1,-1};
        int dy[8] ={0,0,1,-1,1,-1,-1,1};

        vector<vector<int>> dist(n,vector<int> (m,INT_MAX));
        queue<pair<int,int>> q;

        q.push({0,0});
        dist[0][0]=1;
        while(!q.empty()){
            
            int x = q.front().first;
            int y = q.front().second;

            q.pop();
            for(int i = 0 ; i< 8 ; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx>=0 && ny>=0 && nx<n && ny<m && !grid[nx][ny]){
                    if(1+dist[x][y]<dist[nx][ny]){
                        dist[nx][ny]=1+dist[x][y];
                        q.push({nx,ny});

                        if(nx==n-1 && ny==m-1) return dist[nx][ny];
                    }
                }
            }
        }
        return -1;
        
    }
};
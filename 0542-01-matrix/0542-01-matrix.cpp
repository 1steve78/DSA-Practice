class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>>q;
        
        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,-1,1};

        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }

        while(!q.empty()){
            int r= q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0;i<4;i++){
                int nr = r +dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    if(ans[nr][nc]> ans[r][c]+1){
                        ans[nr][nc]=ans[r][c]+1;
                        q.push({nr,nc});
                    }
                }
            }
        }
        return ans;

    }
};
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size() , m = obstacleGrid[0].size();

        vector<vector<int>> dp(n ,vector<int> (m,0));

        if (obstacleGrid[0][0] == 1)
            return 0;

        dp[0][0]=1;
        for(int i= 0;i < n ;i++){
            for(int j = 0 ; j<m  ; j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                    continue;
                }
                if(i==0 && j==0) continue;

                int top=0 ,left =0 ;

                if(i>0){
                    top= dp[i-1][j];
                }

                if(j>0){
                    left = dp[i][j-1];
                }

                dp[i][j] = top+left;
            }
        }

        return dp[n-1][m-1];
    }
};
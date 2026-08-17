class Solution {
public:
    int dp[501][501];
    int solve(int i , int j , vector<int>& stoneValue , vector<int> & prefix){
        if(i == j )return 0;

        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0 ;
        for(int k = i ; k< j; k++){
            int leftSum = prefix[k+1] - prefix[i];
            int rightSum = prefix[j+1] - prefix[k+1];

    
            if(leftSum<rightSum){
                ans = max(ans,leftSum + solve(i,k,stoneValue , prefix));
            }else if( leftSum> rightSum){
                ans = max(ans, rightSum + solve(k+1,j,stoneValue , prefix));
            }else{
                ans = max(ans,
                          leftSum + max(solve(i, k, stoneValue , prefix),
                                        solve(k + 1, j, stoneValue , prefix)));

            }
        }
        return dp[i][j]=ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        
        int n = stoneValue.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        
        memset(dp,-1,sizeof(dp));

        return  solve(0,n-1,stoneValue,prefix);
    }
};
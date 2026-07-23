class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int INF = 1e9;
        vector<vector<int>> dp ( n+1 , vector<int>(amount +1,INF));

        for(int i = 0 ; i <= n ; i++) dp[i][0]=0;

        for(int i=n-1 ; i>=0 ; i--){
            for(int a =1 ;a<=amount ;a++){
                int take = INF;
                if (coins[i] <= a)
                    take = 1 + dp[i][a - coins[i]];


                int notTake = dp[i+1][a];

                dp[i][a] = min(take,notTake);
            }
        }
      
        return dp[0][amount]==INF?-1:dp[0][amount];
    }
};
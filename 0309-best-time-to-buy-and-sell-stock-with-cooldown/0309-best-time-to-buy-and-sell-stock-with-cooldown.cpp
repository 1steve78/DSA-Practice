class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int buy,vector<int> & prices){

        if(i>=prices.size()) return 0;

        if(dp[i][buy]!=-1) return dp[i][buy];
        int profit=0;
        if(buy){
            profit = max(solve(i+1,0,prices)-prices[i],solve(i+1,1,prices));
        } else{
            profit = max(solve(i+2,1,prices)+prices[i],solve(i+1,0,prices));
        }

        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.assign(n , vector<int>(2,-1));

        return solve(0,1,prices);
    }
};